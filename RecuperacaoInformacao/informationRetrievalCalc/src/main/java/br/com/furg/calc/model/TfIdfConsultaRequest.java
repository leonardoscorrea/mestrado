package br.com.furg.calc.model;

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

	public int getQuantidadeTermo() {
		return quantidade_termo;
	}
	public void setQuantidadeTermo(int quantidade_termo) {
		this.quantidade_termo = quantidade_termo;
	}
	public int getMaiorValorTermoLista() {
		return maior_valor_termo_lista;
	}
	public void setMaiorValorTermoLista(int maior_valor_termo_lista) {
		this.maior_valor_termo_lista = maior_valor_termo_lista;
	}
	
}
