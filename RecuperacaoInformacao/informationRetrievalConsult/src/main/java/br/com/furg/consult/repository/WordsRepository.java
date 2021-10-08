package br.com.furg.consult.repository;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import br.com.furg.consult.entity.*;

public interface WordsRepository  extends JpaRepository<Words, Long> {
	
	@Query(value="select w.id, w.word, count(1) as df, w.idf from words w inner join file_word fw on fw.word_id = w.id where fw.frequence<>0  group by w.id, w.word, w.idf;",
			nativeQuery = true)
	public List<Words> findAllCalculatingDF();
	@Query(value="select * from words where word=?1",
			nativeQuery = true)
	public List<Words> findByWord(String name);

}
