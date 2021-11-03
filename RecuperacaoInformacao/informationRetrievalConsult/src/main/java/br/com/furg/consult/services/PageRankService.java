package br.com.furg.consult.services;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

import org.hibernate.dialect.ResultColumnReferenceStrategy;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import br.com.furg.consult.entity.FileWord;
import br.com.furg.consult.entity.Files;
import br.com.furg.consult.entity.PageLink;
import br.com.furg.consult.entity.Pages;
import br.com.furg.consult.entity.Words;
import br.com.furg.consult.model.*;
import br.com.furg.consult.repository.FileWordRepository;
import br.com.furg.consult.repository.FilesRepository;
import br.com.furg.consult.repository.PageLinkRepository;
import br.com.furg.consult.repository.PagesRepository;
import br.com.furg.consult.repository.WordsRepository;
import br.com.furg.consult.util.Util;

@Service
public class PageRankService {
	@Autowired
	private FilesRepository filesRepository;
	@Autowired
	private WordsRepository wordsRepository;
	@Autowired
	private PagesRepository pagesRepository;
	@Autowired
	private PageLinkRepository pageLinkRepository;
	@Autowired
	private FileWordRepository fileWordRepository;
	public CalculateService calculateService;
	
	public PageRankService() {
		calculateService = new CalculateService();
	}
	
	public List<Pages> getAllPages(){
		return pagesRepository.findAll();
	}
	
	public List<RelationListResponse> RelationList(){
		List<Pages> listPages = pagesRepository.findAll();
		List<PageLink> listPageLink = pageLinkRepository.findAll();
		List<RelationListResponse> result = new ArrayList<RelationListResponse>();
		for(Pages p : listPages) {
			RelationListResponse rlr = new RelationListResponse();
			rlr.setPage(p);
			List<PageLink> listAux = listPageLink.stream().filter(pl -> pl.getPageOriginId() == p.getId()).collect(Collectors.toList());
			for(PageLink pl : listAux) {
				Pages pAux = listPages.stream().filter(pg -> pg.getId() == pl.getPageTargetId()).collect(Collectors.toList()).get(0);
				rlr.addRelation(pAux);
			}
			result.add(rlr);
		}
		
		return result;
	}
	
	
	public List<String> indexar(){
		File folder = new File("/var/www/html/paginasPageRank");
		pagesRepository.deleteAll();
		pageLinkRepository.deleteAll();
		List<File> listFiles = findAllFilesInFolder(folder);
		List<String> result = new ArrayList<String>();
		
		String REGEX = "(href=\")(.*?)(?=\")";
		Pattern pattern = Pattern.compile(REGEX);
		//Matcher matcher = pattern.matcher("/var/www/html/paginasPageRank/paginaB.html");
		
		
		List<Pages> pages = new ArrayList<Pages>();
		
		
		for(File f : listFiles) {
			Pages p = new Pages();
			p.setName(f.getName().replace(".html", ""));
			p.setLink(f.getName());
			p.setCollectionId(2);
			pagesRepository.save(p);
			pages.add(p);
			result.add(p.getLink());
		}
		
		//PageLink pl = new PageLink();
		//pl.setPageOriginId(1);
		//pl.setPageTargetId(10);
		
		//pageLinkRepository.save(pl);
		
		for(File f : listFiles) {
			BufferedReader reader;
			//List<>listFileWord.stream().filter(fw -> fw.getWordId() == wordId).collect(Collectors.toList())
			//INSERIR LINK
			String originLink = f.getName();
			Pages pOrigin = pages.stream().filter(pg -> pg.getLink().equals(originLink)).collect(Collectors.toList()).get(0);
			try {
				reader = new BufferedReader(new FileReader(f));
			
		       final StringBuilder contents = new StringBuilder();
		       while(reader.ready()) {
		           contents.append(reader.readLine());
		       }
		       reader.close();
		       final String stringContents = contents.toString();
		       Matcher matcher = pattern.matcher(stringContents);
		       while (matcher.find()) {
				      // Get the matching string
				      String match = matcher.group(2);
				      Pages pTarget = pages.stream().filter(pg -> pg.getLink().equals(match)).collect(Collectors.toList()).get(0);
				      PageLink pl = new PageLink();
					  pl.setPageOriginId(pOrigin.getId());
					  pl.setPageTargetId(pTarget.getId());
						
					  pageLinkRepository.save(pl);
				      System.out.println(match);
				    }
		       /*if(stringContents.toString().matches(".*a.*")) {
		           //stringContents.replaceAll("a", "b");
		           //final BufferedWriter writer = new BufferedWriter(new FileWriter(file));
		           //writer.write(stringContents);
		           //writer.close();
		       }*/
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return result;
	}
	
	public List<File> findAllFilesInFolder(File folder) {
		List<File> result = new ArrayList<File>();
		for (File file : folder.listFiles()) {
			if (!file.isDirectory()) {
				result.add(file);
			} else {
				findAllFilesInFolder(file);
			}
		}
		return result;
	}
}
