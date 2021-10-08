package br.com.furg.consult.services;


import org.springframework.web.client.RestTemplate;

import br.com.furg.consult.model.*;

public class CalculateService {
	
	public Double calculateIDF(int quantidade_arquivos, int documento_frequence) {
		RestTemplate rt = new RestTemplate();
		System.out.println("arquivos: "+quantidade_arquivos+" == df: "+documento_frequence);
		Idf result = rt.getForObject("http://localhost:8080/vetorial/arquivos/calcIdf?quantidade_arquivos="+quantidade_arquivos+"&document_frequence="+documento_frequence, Idf.class);
		return result.getIdf(); 
	}
	
	public Double calculateTF(int quantidade_termo, int maior_valor_termo_lista) {
		RestTemplate rt = new RestTemplate();
		System.out.println("arquivos: "+quantidade_termo+" == df: "+maior_valor_termo_lista);
		Tf result = rt.getForObject("http://localhost:8080/vetorial/arquivos/calcTf?quantidade_termo="+quantidade_termo+"&maior_valor_termo_lista="+maior_valor_termo_lista, Tf.class);
		return result.getTf(); 
	}
	
	public Double calculateTFIDF(Double tf, Double idf) {
		RestTemplate rt = new RestTemplate();
		System.out.println("tf: "+tf+" == idf: "+idf);
		TfIdf result = rt.getForObject("http://localhost:8080/vetorial/arquivos/calcTfIdf2?tf="+tf+"&idf="+idf, TfIdf.class);
		return result.getTfIdf(); 
	}
	/*
	public Double calculatePost(int quantidade_arquivos, int documento_frequence) {
		RestTemplate rt = new RestTemplate();
		HttpHeaders headers = new HttpHeaders();
		IdfRequest idfRequest = new IdfRequest();
		idfRequest.setQuantidade_arquivos(quantidade_arquivos);
		idfRequest.setDocument_frequence(documento_frequence);
		HttpEntity<IdfRequest> request = new HttpEntity<>(idfRequest, headers);
		ResponseEntity<Idf> result = rt.postForEntity("http://localhost:8080/vetorial/arquivos/calcIdf", request, Idf.class);
		return Double.valueOf("0.3"); 
	}*/

	public Double calculateTFConsult(int quantidade_termo, int maior_valor_termo_lista) {
		RestTemplate rt = new RestTemplate();
		System.out.println("arquivos: "+quantidade_termo+" == df: "+maior_valor_termo_lista);
		TfConsulta result = rt.getForObject("http://localhost:8080/vetorial/consultas/calcTfConsulta?quantidade_termo="+quantidade_termo+"&maior_valor_termo_lista="+maior_valor_termo_lista, TfConsulta.class);
		return result.getTf(); 
	}
	
	public Double calculateTfIdfConsult(Double idf, int quantidade_termo, int maior_valor_termo_lista) {
		RestTemplate rt = new RestTemplate();
		System.out.println("IDF: "+idf+" arquivos: "+quantidade_termo+" == df: "+maior_valor_termo_lista);
		TfIdf result = rt.getForObject("http://localhost:8080/vetorial/consultas/calcTfIdfConsulta?idf="+idf+"&quantidadeTermo="+quantidade_termo+"&maiorValorTermoLista="+maior_valor_termo_lista, TfIdf.class);
		return result.getTfIdf(); 
	}
}
