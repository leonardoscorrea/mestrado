package br.com.furg.consult.model;

public class TfConsulta {

	private int quantidade_termo;
	private int maior_valor_termo_lista;
	private double tf;
	
	public TfConsulta() {
		this.quantidade_termo =0;
		this.maior_valor_termo_lista=0;
		this.tf = 0.0;
	}
	
	public TfConsulta(int quantidade_termo, int maior_valor_termo_lista) {
		this.quantidade_termo = quantidade_termo;
		this.maior_valor_termo_lista = maior_valor_termo_lista;
	}
	
	public double getTf() {
		return tf;
	}
	public void setTf(double tf) {
		this.tf = tf;
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
