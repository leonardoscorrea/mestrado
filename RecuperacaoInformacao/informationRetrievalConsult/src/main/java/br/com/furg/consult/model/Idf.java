package br.com.furg.consult.model;


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
	}
	
	public int getQuantidade_arquivos() {
		return quantidade_arquivos;
	}
	public void setQuantidade_arquivos(int quantidade_arquivos) {
		this.quantidade_arquivos = quantidade_arquivos;
	}
	public int getDocument_frequence() {
		return document_frequence;
	}
	public void setDocument_frequence(int document_frequence) {
		this.document_frequence = document_frequence;
	}
	
	public Double getIdf() {
		return idf;
	}

}
