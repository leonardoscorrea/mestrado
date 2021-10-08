package br.com.furg.consult.model;

public class TfIdfRequest {
	
	private int quantidade_arquivos;
	private int document_frequence;
	private int quantidade_termo;
	private int maior_valor_termo_lista;
	
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
	public int getQuantidade_termo() {
		return quantidade_termo;
	}
	public void setQuantidade_termo(int quantidade_termo) {
		this.quantidade_termo = quantidade_termo;
	}
	public int getMaior_valor_termo_lista() {
		return maior_valor_termo_lista;
	}
	public void setMaior_valor_termo_lista(int maior_valor_termo_lista) {
		this.maior_valor_termo_lista = maior_valor_termo_lista;
	}

}
