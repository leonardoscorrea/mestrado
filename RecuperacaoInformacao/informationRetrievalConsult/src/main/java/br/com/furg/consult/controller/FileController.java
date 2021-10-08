package br.com.furg.consult.controller;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import br.com.furg.consult.entity.*;
import br.com.furg.consult.repository.FileWordRepository;
import br.com.furg.consult.repository.FilesRepository;
import br.com.furg.consult.repository.WordsRepository;
import br.com.furg.consult.services.CalculateService;

@RequestMapping("/file")
@RestController
public class FileController {
	
	@Autowired
	public FilesRepository filesRepository;
	@Autowired
	public WordsRepository wordsRepository;
	@Autowired
	public FileWordRepository fileWordRepository;
	public CalculateService calculateService;
	
	public FileController() {
		this.calculateService = new CalculateService();
	}
	
	@RequestMapping(value = "/indexing", method = RequestMethod.GET)
	public ResponseEntity<Void> indexing(){
		List<Files> listFiles = filesRepository.findAll();
		List<Words> listWords = wordsRepository.findAllCalculatingDF();
		List<FileWord> listFileWords = fileWordRepository.findAll();
		
		//calcula IDF
		for(int i = 0; i < listWords.size() ;i++) {
			Double idf = calculateService.calculateIDF(listFiles.size(), listWords.get(i).getDf());
			listWords.get(i).setIdf(idf);
			wordsRepository.save(listWords.get(i));
		}
		
		//calcula TF e TFIDF
		for(int i = 0; i < listFiles.size() ;i++) {
			Long fileId = listFiles.get(i).getId();
			FileWord x = listFileWords.stream().filter(f -> f.getFileId() == fileId).max(Comparator.comparingInt(FileWord::getFrequence)).get();
			List<FileWord> listFwAux = listFileWords.stream().filter(fw -> fw.getFileId() == fileId).collect(Collectors.toList());
			for(int j = 0; j < listFwAux.size();j++) {
				int wordId = listFwAux.get(j).getWordId();
				List<Words> wAux = listWords.stream().filter(w -> w.getId() == wordId).collect(Collectors.toList());
				Double tf = calculateService.calculateTF(listFwAux.get(j).getFrequence(), x.getFrequence());
				Double tfidf = 0.0;
				if(wAux.size() > 0) {
					tfidf = calculateService.calculateTFIDF(tf, wAux.get(0).getIdf());
				}
				FileWord fwAux = new FileWord();
				fwAux.setTf(tf);
				fwAux.setTfidf(tfidf);
				fwAux.setFileId(listFwAux.get(j).getFileId());
				fwAux.setFrequence(listFwAux.get(j).getFrequence());
				fwAux.setWordId(listFwAux.get(j).getWordId());
				fileWordRepository.save(fwAux);
				System.out.println("AQUIIII TFFF => "+listFwAux.get(j).getFrequence() + " = " + x.getFrequence() + " = TF: "+ tf);
			}
			System.out.println("Teste: " + x.getFrequence() + " teste: " + x.getWordId());
		}
		return new ResponseEntity<Void>(HttpStatus.OK);
	}

}
