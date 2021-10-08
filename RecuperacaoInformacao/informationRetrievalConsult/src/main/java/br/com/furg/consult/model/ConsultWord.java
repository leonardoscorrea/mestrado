package br.com.furg.consult.model;

public class ConsultWord {
	String word;
	int frequence;
	Double tf;
	Double tfItf;
	Double idf;
	
	public Double getIdf() {
		return idf;
	}

	public void setIdf(Double idf) {
		this.idf = idf;
	}

	public ConsultWord() {
		this.word = "";
		this.frequence = 0;
		this.tf = 0.0;
		this.tfItf = 0.0;
	}
	
	public String getWord() {
		return word;
	}
	public void setWord(String word) {
		this.word = word;
	}
	public int getFrequence() {
		return frequence;
	}
	public void setFrequence(int frequence) {
		this.frequence = frequence;
	}
	public Double getTf() {
		return tf;
	}
	public void setTf(Double tf) {
		this.tf = tf;
	}
	public Double getTfItf() {
		return tfItf;
	}
	public void setTfItf(Double tfItf) {
		this.tfItf = tfItf;
	}
	
	public void incrementFrequence() {
		this.frequence++;
	}
}
