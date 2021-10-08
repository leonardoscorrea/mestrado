package br.com.furg.calc.model;

public class Tf {
	
	private int quantidade_termo;
	private int maior_valor_termo_lista;
	private double tf;
	
	public Tf(int quantidade_termo, int maior_valor_termo_lista) {
		this.quantidade_termo = quantidade_termo;
		this.maior_valor_termo_lista = maior_valor_termo_lista;
		this.tf = calculaTf();
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
		this.tf = calculaTf();
		
	}
	public int getMaior_valor_termo_lista() {
		return maior_valor_termo_lista;
	}
	public void setMaior_valor_termo_lista(int maior_valor_termo_lista) {
		this.maior_valor_termo_lista = maior_valor_termo_lista;
		this.tf = calculaTf();
	}
	
	public double calculaTf() {
		if(quantidade_termo != 0 && maior_valor_termo_lista != 0)
			return (double)quantidade_termo/(double)maior_valor_termo_lista;
		else return 0;
	}

}
