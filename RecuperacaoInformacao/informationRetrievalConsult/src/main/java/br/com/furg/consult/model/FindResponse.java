package br.com.furg.consult.model;

import java.util.ArrayList;
import java.util.List;

public class FindResponse {

	List<ConsultWord> listConsultWords;
	List<FileConsult> listFileConsult; 
	List<VetorialModel> listVetorialModel;
	
	public FindResponse() {
		listConsultWords = new ArrayList<>();
		listFileConsult = new  ArrayList<>();
		listVetorialModel = new ArrayList<>();
	}
	
	public List<VetorialModel> getListVetorialModel() {
		return listVetorialModel;
	}

	public void setListVetorialModel(List<VetorialModel> listVetorialModel) {
		this.listVetorialModel = listVetorialModel;
	}

	public void addVetorialModel(VetorialModel vetorialModel) {
		this.listVetorialModel.add(vetorialModel);
	}
	
	public void addFileConsult(FileConsult fc) {
		listFileConsult.add(fc);
	}
	
	public List<FileConsult> getListFileConsult() {
		return listFileConsult;
	}

	public void setListFileConsult(List<FileConsult> listFileConsult) {
		this.listFileConsult = listFileConsult;
	}

	

	public void addConsultWord(ConsultWord c) {
		listConsultWords.add(c);
	}

	public List<ConsultWord> getListConsultWords() {
		return listConsultWords;
	}

	public void setListConsultWords(List<ConsultWord> listConsultWords) {
		this.listConsultWords = listConsultWords;
	}

}
