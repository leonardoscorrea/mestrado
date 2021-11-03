package br.com.furg.consult.repository;


import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import br.com.furg.consult.entity.*;

@Repository
public interface PageLinkRepository extends JpaRepository<PageLink, Long>{

}
