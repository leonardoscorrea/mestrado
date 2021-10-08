package br.com.furg.calc.model;


public class Idf {

	private int quantidade_arquivos;
	private int document_frequence;
	private Double idf;
	
	public Idf() {
		super();
		this.quantidade_arquivos = 0;
		this.document_frequence = 0;
		idf = 0.0;
	}
	
	public Idf(int quantidade_arquivos, int document_frequence) {
		super();
		this.quantidade_arquivos = quantidade_arquivos;
		this.document_frequence = document_frequence;
		idf = calculaIdf();
	}
	
	public int getQuantidade_arquivos() {
		return quantidade_arquivos;
	}
	public void setQuantidade_arquivos(int quantidade_arquivos) {
		this.quantidade_arquivos = quantidade_arquivos;
		this.idf = calculaIdf();
	}
	public int getDocument_frequence() {
		return document_frequence;
	}
	public void setDocument_frequence(int document_frequence) {
		this.document_frequence = document_frequence;
		this.idf = calculaIdf();
	}
	
	public Double getIdf() {
		return idf;
	}
	
	public Double calculaIdf() {
		if(quantidade_arquivos != 0 && document_frequence != 0) {
			return Math.log10(Double.valueOf(quantidade_arquivos)/Double.valueOf(document_frequence));
		}
		return 0.0;
	}
}
