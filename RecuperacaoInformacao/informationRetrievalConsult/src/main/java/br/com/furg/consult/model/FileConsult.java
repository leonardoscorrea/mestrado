package br.com.furg.consult.model;

import java.util.ArrayList;
import java.util.List;

import br.com.furg.consult.entity.FileWord;

public class FileConsult {
	
	private FileWord fileWord;
	private Double indices;
	private Double totalIndice;
	
	public FileConsult() {
		this.indices = 0.0;
		this.totalIndice = 0.0;
	}
	

	
	public FileWord getFileWord() {
		return fileWord;
	}
	public void setFileWord(FileWord fileWord) {
		this.fileWord = fileWord;
	}
	public Double getIndices() {
		return indices;
	}
	public void setIndices(Double indices) {
		this.indices = indices;
	}
	public Double getTotalIndice() {
		return totalIndice;
	}
	public void setTotalIndice(Double totalIndice) {
		this.totalIndice = totalIndice;
	}

}
