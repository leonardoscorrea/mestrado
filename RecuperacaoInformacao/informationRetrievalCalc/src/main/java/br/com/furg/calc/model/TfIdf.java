package br.com.furg.calc.model;

public class TfIdf {
	
	private Double tf;
	private Double idf;
	private Double tfIdf;
	
	public Double getTfIdf() {
		return tfIdf;
	}

	public void setTfIdf(Double tfIdf) {
		this.tfIdf = tfIdf;
	}

	public TfIdf(Double tf, Double idf) {
		this.idf = idf;
		this.tf = tf;
		this.tfIdf = calculaTfIdf();
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
	
	public Double calculaTfIdf() {
		if(this.tf != 0 && this.idf != 0 ){
			return this.tf*this.idf;
		} else return 0.0;
	}

}
