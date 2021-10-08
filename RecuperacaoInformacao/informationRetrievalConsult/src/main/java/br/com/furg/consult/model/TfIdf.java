package br.com.furg.consult.model;

public class TfIdf {
	
	private Double tf;
	private Double idf;
	private Double tfIdf;
	
	public TfIdf() {
		this.tf = 0.0;
		this.idf = 0.0;
		this.tfIdf = 0.0;
	}
	
	public Double getTfIdf() {
		return tfIdf;
	}

	public void setTfIdf(Double tfIdf) {
		this.tfIdf = tfIdf;
	}

	public TfIdf(Double tf, Double idf) {
		this.idf = idf;
		this.tf = tf;
	}
	
	public Double getTf() {
		return tf;
	}
	public void setTf(Double tf) {
		this.tf = tf;
	}
	public Double getIdf() {
		return idf;
	}
	public void setIdf(Double idf) {
		this.idf = idf;
	}
	


}
