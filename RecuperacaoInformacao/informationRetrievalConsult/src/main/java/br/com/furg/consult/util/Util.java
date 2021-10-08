package br.com.furg.consult.util;

import java.text.Normalizer;
import java.util.regex.Pattern;

public abstract class Util {

	public static String removerAcentos(String str) {
		String aux = Normalizer.normalize(str, Normalizer.Form.NFD).replaceAll("[^\\p{ASCII}]", ""); 
		aux = aux.replaceAll("[^a-zA-Z0-9 ]", "");
	    return aux.toLowerCase();
	}
	
	public static String deAccent(String str) {
	    String nfdNormalizedString = Normalizer.normalize(str, Normalizer.Form.NFD); 
	    Pattern pattern = Pattern.compile("\\p{InCombiningDiacriticalMarks}+");
	    String aux = pattern.matcher(nfdNormalizedString).replaceAll("");
	    aux = aux.replaceAll("[^a-zA-Z0-9 ]", "");
	    return aux.toLowerCase(); 
	}
}
