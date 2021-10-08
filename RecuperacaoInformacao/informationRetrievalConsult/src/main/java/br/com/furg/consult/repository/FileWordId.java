package br.com.furg.consult.repository;

import java.io.Serializable;


public class FileWordId   implements Serializable  {

	private static final long serialVersionUID = 1L;
	private int wordId;
	private int fileId;
	
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
}
