package br.com.furg.consult.model;

public class TfIdfConsultaRequest {

	private int quantidade_termo;
	private int maior_valor_termo_lista;
	private double idf;
	
	public double getIdf() {
		return idf;
	}
	public void setIdf(double idf) {
		this.idf = idf;
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
