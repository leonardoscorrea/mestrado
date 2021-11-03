package br.com.furg.consult.entity;


import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.Table;

import br.com.furg.consult.repository.PageLinkId;

@Entity
@Table(name = "page_link")
@IdClass(PageLinkId.class)
public class PageLink {
	
	@Id
	private Long pageOriginId;
	@Id
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
