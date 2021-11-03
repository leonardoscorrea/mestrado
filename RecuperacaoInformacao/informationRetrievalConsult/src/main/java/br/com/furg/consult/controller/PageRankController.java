package br.com.furg.consult.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import br.com.furg.consult.entity.Pages;
import br.com.furg.consult.model.RelationListResponse;
import br.com.furg.consult.services.PageRankService;

@RequestMapping("/pagerank")
@RestController
public class PageRankController {
	@Autowired
	private PageRankService pagerankService;
	
	public PageRankController() {
		pagerankService =  new PageRankService();
	}
	
	@RequestMapping(value = "/indexar", method = RequestMethod.GET)
	public List<String> getIndexing(){
		return pagerankService.indexar();
	}
	
	@RequestMapping(value = "/relationList", method = RequestMethod.GET)
	public List<RelationListResponse> getRelationList(){
		return pagerankService.RelationList();
	}
	
	@RequestMapping(value = "/pages", method = RequestMethod.GET)
	public List<Pages> getAllPages(){
		return pagerankService.getAllPages();
	}
	
	
	
	
}
