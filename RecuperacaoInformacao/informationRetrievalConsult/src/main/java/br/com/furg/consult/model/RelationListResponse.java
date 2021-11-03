package br.com.furg.consult.model;

import java.util.ArrayList;
import java.util.List;

import br.com.furg.consult.entity.Pages;

public class RelationListResponse {
	private Pages page;
	private List<Pages> relations = new ArrayList<Pages>();
	public Pages getPage() {
		return page;
	}
	public void setPage(Pages page) {
		this.page = page;
	}
	public List<Pages> getRelations() {
		return relations;
	}
	public void setRelations(List<Pages> relations) {
		this.relations = relations;
	}
	
	public void addRelation(Pages p) {
		this.relations.add(p);
	}
}
