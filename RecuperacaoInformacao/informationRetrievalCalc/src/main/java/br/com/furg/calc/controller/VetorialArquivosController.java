package br.com.furg.calc.controller;


import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import br.com.furg.calc.model.*;


@RequestMapping("/vetorial/arquivos")
@RestController
public class VetorialArquivosController {

	
	@RequestMapping(value = "/calcIdf", method = RequestMethod.GET)
    public ResponseEntity<Idf> calcIdf(IdfRequest request) {
		Idf response = new Idf(request.getQuantidade_arquivos(),request.getDocument_frequence());
        return new ResponseEntity<>(response,HttpStatus.OK);
    }
	
	@RequestMapping(value = "/calcTf", method = RequestMethod.GET)
    public ResponseEntity<Tf> calcTf(TfRequest request) {
		Tf response = new Tf(request.getQuantidade_termo(),request.getMaior_valor_termo_lista());
        return new ResponseEntity<>(response,HttpStatus.OK);
    }
	
	@RequestMapping(value = "/calcTfIdf", method = RequestMethod.GET)
    public ResponseEntity<TfIdf> calcTfIdf(TfIdfRequest request) {
		TfIdf response = new TfIdf(new Tf(request.getQuantidade_termo(),request.getMaior_valor_termo_lista()).getTf(),new Idf(request.getQuantidade_arquivos(),request.getDocument_frequence()).getIdf());
        return new ResponseEntity<>(response,HttpStatus.OK);
    }
	
	@RequestMapping(value = "/calcTfIdf2", method = RequestMethod.GET)
    public ResponseEntity<TfIdf> calcTfIdf2(TfIdfRequest2 request) {
		TfIdf response = new TfIdf(request.getTf(), request.getIdf());
        return new ResponseEntity<>(response,HttpStatus.OK);
    }
}
