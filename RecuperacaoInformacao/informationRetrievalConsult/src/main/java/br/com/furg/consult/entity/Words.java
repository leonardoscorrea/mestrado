package br.com.furg.consult.entity;


import javax.persistence.*;

@Entity
public class Words {
	@Id
	   @GeneratedValue(strategy = GenerationType.IDENTITY)
	   private Long id;
	private String word;
	private int df;
	private Double idf;
	
	public int getDf() {
		return df;
	}
	public void setDf(int df) {
		this.df = df;
	}
	
	
	public Double getIdf() {
		return idf;
	}
	public void setIdf(Double idf) {
		this.idf = idf;
	}
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public String getWord() {
		return word;
	}
	public void setWord(String word) {
		this.word = word;
	}
}
