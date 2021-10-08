package br.com.furg.consult.model;

import java.util.ArrayList;
import java.util.List;

public class Consult {

	List<ConsultWord> listConsultWords;
	
	public Consult(){
		listConsultWords = new ArrayList<>();
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
