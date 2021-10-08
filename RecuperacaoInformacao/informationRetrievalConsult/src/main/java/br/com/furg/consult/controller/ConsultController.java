package br.com.furg.consult.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import br.com.furg.consult.entity.FileWord;
import br.com.furg.consult.model.FindRequest;
import br.com.furg.consult.model.FindResponse;
import br.com.furg.consult.repository.FileWordRepository;
import br.com.furg.consult.repository.FilesRepository;
import br.com.furg.consult.repository.WordsRepository;
import br.com.furg.consult.services.ConsultService;

@RequestMapping("/consult")
@RestController
public class ConsultController {
	@Autowired
	private ConsultService consultService;
	
	public ConsultController() {
		consultService =  new ConsultService();
	}
	
	@RequestMapping(value = "/files", method = RequestMethod.GET)
	public List<String> getAllFiles(){
		return consultService.getAllFiles();
	}
	
	@RequestMapping(value = "/words", method = RequestMethod.GET)
	public List<String> getAllWords(){
		return consultService.getAllWords();
	}
	
	@RequestMapping(value = "/frequence", method = RequestMethod.GET)
	public List<FileWord> getAllFileWord(){
		return consultService.getAllFileWord();
	}
	
	@RequestMapping(value = "/find", method = RequestMethod.POST)
	public ResponseEntity<FindResponse> getAllFileWord(@RequestBody FindRequest s){
		return new ResponseEntity<>(consultService.consultQuery(s), HttpStatus.OK);
	}

}
