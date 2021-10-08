package br.com.furg.consult.services;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import br.com.furg.consult.entity.FileWord;
import br.com.furg.consult.entity.Files;
import br.com.furg.consult.entity.Words;
import br.com.furg.consult.model.*;
import br.com.furg.consult.repository.FileWordRepository;
import br.com.furg.consult.repository.FilesRepository;
import br.com.furg.consult.repository.WordsRepository;
import br.com.furg.consult.util.Util;

@Service
public class ConsultService {
	@Autowired
	private FilesRepository filesRepository;
	@Autowired
	private WordsRepository wordsRepository;
	@Autowired
	private FileWordRepository fileWordRepository;
	public CalculateService calculateService;
	
	public ConsultService() {
		calculateService = new CalculateService();
	}
	
	
	public List<String> getAllFiles(){
		List<String> response = new ArrayList<String>();
		filesRepository.findAll().forEach(it -> {response.add(it.getName());});
		return response;
	}
	
	public List<String> getAllWords(){
		List<String> response = new ArrayList<String>();
		wordsRepository.findAll().forEach(it -> {response.add(it.getWord());});
		return response;
	}
	
	public List<FileWord> getAllFileWord(){
		return fileWordRepository.findAll();
	}

	
	public FindResponse consultQuery(FindRequest q) {
		
		FindResponse response = new FindResponse();
		List<Files> listFiles = filesRepository.findAll();
		List<FileWord> listFileWord = fileWordRepository.findAll();
		List<Words> listWords = wordsRepository.findAll();
		
	  	System.out.println("Aqui => " + wordsRepository.findByWord("boi").size());
		
		List<String> items = new ArrayList<String>(Arrays.asList(Util.deAccent(q.getQuery()).split(" ")));
		for (int i = 0; i < items.size(); i++) {
			String st = items.get(i);
			List<Words> wAux = new ArrayList<>();
			if(!st.isEmpty())
				//otimização
				wAux = wordsRepository.findByWord(st);
				if(wAux.size() > 0) {
					if(response.getListConsultWords().stream().filter(cw -> cw.getWord().equals(st)).collect(Collectors.toList()).size() > 0) {
						response.getListConsultWords().stream().filter(cw -> cw.getWord().equals(st)).collect(Collectors.toList()).get(0).incrementFrequence();
					} else {
						ConsultWord newCW = new ConsultWord();
						newCW.setWord(st);
						newCW.setFrequence(1);
						newCW.setIdf(wAux.get(0).getIdf());
						response.addConsultWord(newCW);
					}
				}
		}
		
		//CALCULA TF E TFIDF DA CONSULTA
		ConsultWord consultWord = response.getListConsultWords().stream().max(Comparator.comparingInt(ConsultWord::getFrequence)).get();
		for(int i = 0; i < response.getListConsultWords().size();i++) {
			response.getListConsultWords().get(i).setTf(calculateService.calculateTFConsult(response.getListConsultWords().get(i).getFrequence(), consultWord.getFrequence()));
			response.getListConsultWords().get(i).setTfItf(calculateService.calculateTfIdfConsult(response.getListConsultWords().get(i).getIdf(),response.getListConsultWords().get(i).getFrequence(), consultWord.getFrequence()));
			System.out.println("TF da Consulta: "+response.getListConsultWords().get(i).getTf()+" IDF: "+response.getListConsultWords().get(i).getIdf()+" TF x IDF: "+ response.getListConsultWords().get(i).getTfItf());
		}
		
		//CALCULA O INDICE DE ARQUIVO * CONSULT
		for(int j = 0; j < response.getListConsultWords().size(); j++) {
			String wordStr = response.getListConsultWords().get(j).getWord();
			List<Words> lWords= listWords.stream().filter(w -> w.getWord().equals(wordStr)).collect(Collectors.toList());
			if(lWords.size() > 0) {
				Long wordId = lWords.get(0).getId();
				List<FileWord> fwAux = listFileWord.stream().filter(fw -> fw.getWordId() == wordId).collect(Collectors.toList());
				for(int i = 0; i < fwAux.size(); i++) {
					FileConsult fcAux = new FileConsult();
					fcAux.setFileWord(fwAux.get(i));
					fcAux.setIndices(fwAux.get(i).getTfidf()*response.getListConsultWords().get(j).getTfItf());
					response.addFileConsult(fcAux);
				}
			}
			//fcAux.addIndice(listFileWord.get(i).getTfidf()*list);
		}
		
		for(int i = 0; i < listFiles.size(); i++) {
			//(1) soma indiceFileConsult do arquivo x
			//(2) raiz(soma( tfidfConsulta ^ 2) )
			//(3) raiz(soma( tfidfFileWord ^ 2 ) )
			// (1) / [(2)*(3)]
			VetorialModel vModel = new VetorialModel();
			vModel.setFile(listFiles.get(i));
			vModel.setIndex(0.0);
			
			Double indexSum = 0.0;
			Double raizConsulta = 0.0;
			Double raizArquivoConsulta = 0.0;
			//soma os indices
			List<FileConsult> x = response.getListFileConsult().stream().filter(fc -> fc.getFileWord().getFileId() == vModel.getFile().getId()).collect(Collectors.toList());
			for(int j = 0; j < x.size(); j++) {
				indexSum += x.get(j).getIndices();
			}
			//calcula raiz da consulta
			for(int j = 0; j < response.getListConsultWords().size(); j++) {
				raizConsulta += Math.pow(response.getListConsultWords().get(j).getTfItf(),2);
			}
			raizConsulta = Math.sqrt(raizConsulta);
			
			//calcula raiz do tfidf do arquivo
			List<FileWord> lFWAux = listFileWord.stream().filter(fw -> fw.getFileId() == vModel.getFile().getId()).collect(Collectors.toList());
			for(int j = 0; j < lFWAux.size(); j++) {
				raizArquivoConsulta += Math.pow(lFWAux.get(j).getTfidf(),2);
			}
			raizArquivoConsulta = Math.sqrt(raizArquivoConsulta);
			
			if(raizArquivoConsulta != 0.0 && raizConsulta != 0.0) {
				System.out.println("indexSum: "+indexSum+" raizConsulta: "+raizConsulta+" raizArquivoConsulta:"+raizArquivoConsulta);
				vModel.setIndex((indexSum/(raizConsulta*raizArquivoConsulta)));
			} else {
				vModel.setIndex(0.0);
			}
			
			
			
			response.addVetorialModel(vModel);
					
		}
		
		return response;
	}

}
