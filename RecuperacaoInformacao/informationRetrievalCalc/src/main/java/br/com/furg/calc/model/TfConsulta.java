package br.com.furg.calc.model;

public class TfConsulta {

	private int quantidade_termo;
	private int maior_valor_termo_lista;
	private Double tf;
	private Double alfa = 0.5;
	
	public TfConsulta(int quantidade_termo, int maior_valor_termo_lista) {
		this.quantidade_termo = quantidade_termo;
		this.maior_valor_termo_lista = maior_valor_termo_lista;
		this.tf = calculaTf();
	}
	
	public Double getTf() {
		return tf;
	}
	public void setTf(Double tf) {
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
	
	public Double calculaTf() {
		if(quantidade_termo != 0 && maior_valor_termo_lista != 0)
			return this.alfa + ((1-this.alfa)*Double.valueOf(quantidade_termo))/Double.valueOf(maior_valor_termo_lista);
			//return (double)quantidade_termo/(double)maior_valor_termo_lista;
		else return 0.0;
	}
	
}
