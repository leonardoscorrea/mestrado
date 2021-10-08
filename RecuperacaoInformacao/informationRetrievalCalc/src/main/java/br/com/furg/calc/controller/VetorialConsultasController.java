package br.com.furg.calc.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import br.com.furg.calc.model.*;

@RequestMapping("/vetorial/consultas")
@RestController
public class VetorialConsultasController {

	
	@RequestMapping(value = "/calcTfConsulta", method = RequestMethod.GET)
    public TfConsulta calcTf(TfRequest request) {
		TfConsulta response = new TfConsulta(request.getQuantidade_termo(),request.getMaior_valor_termo_lista());
        return response;
    }
	
	@RequestMapping(value = "/calcTfIdfConsulta", method = RequestMethod.GET)
    public TfIdf calcTfIdf(TfIdfConsultaRequest request) {
		TfIdf response = new TfIdf(new TfConsulta(request.getQuantidadeTermo(),request.getMaiorValorTermoLista()).getTf(),request.getIdf());
        return response;
    }

}
