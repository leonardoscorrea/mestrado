package br.com.furg.consult.entity;


import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.Table;

import br.com.furg.consult.repository.FileWordId;

@Entity
@Table(name = "file_word")
@IdClass(FileWordId.class)
public class FileWord {
	
	@Id
	private int wordId;
	@Id
	private int fileId;
	private int frequence;
	private Double tf;
	private Double tfidf;
	

	public Double getTf() {
		return tf;
	}
	public void setTf(Double tf) {
		this.tf = tf;
	}
	public Double getTfidf() {
		return tfidf;
	}
	public void setTfidf(Double tfidf) {
		this.tfidf = tfidf;
	}
	public int getWordId() {
		return wordId;
	}
	public void setWordId(int wordId) {
		this.wordId = wordId;
	}
	public int getFileId() {
		return fileId;
	}
	public void setFileId(int fileId) {
		this.fileId = fileId;
	}
	public int getFrequence() {
		return frequence;
	}
	public void setFrequence(int frequence) {
		this.frequence = frequence;
	}
}
