package br.com.furg.consult.repository;

import java.io.Serializable;


public class PageLinkId   implements Serializable  {

	private static final long serialVersionUID = 1L;
	private Long pageOriginId;
	private Long pageTargetId;
	
	public Long getPageOriginId() {
		return pageOriginId;
	}
	public void setPageOriginId(Long pageOriginId) {
		this.pageOriginId = pageOriginId;
	}
	public Long getPageTargetId() {
		return pageTargetId;
	}
	public void setPageTargetId(Long pageTargetId) {
		this.pageTargetId = pageTargetId;
	}
	
	
}
