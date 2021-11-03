<?php
require_once("util.php");
?>
<head>
    <title>Furg - Recuperação de Informação</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Titillium+Web">
    <style type="text/css">
        html, body {
            height: 100%;
            margin: 0;
            	font-family: 'Titillium Web', sans-serif;
        }

        #wrapper {
            min-height: 100%; 
            border: 0px solid red;
        }
        
        #header{
        	border: 0px solid red;
        }
        
        ul.horizontalMenu {
  		list-style-type: none;
  		margin: 0;
  		padding: 0;
  		overflow: hidden;
		}
		
		ul.horizontalMenu li {
  		float: left;
		}
		
		ul.horizontalMenu li a {
  		display: block;
  		color: black;
  		text-align: center;
  		padding: 16px;
  		text-decoration: none;
		}
		
		ul.horizontalMenu li a:hover {
  		background-color: orange;
		}
		
		#logoBuscador{
			font-size:150px;
			text-align:center;
			border: 0px solid red;
			margin:0px;
			padding:0px;
		}
		#logoBuscador p{
			margin:0px;
			padding:0px;
		}
		#logoBuscador span{
			padding:0px;
			margin: 0px;
		}
		
		#formularioBuscador{
			text-align:center;
			margin: 10px auto;
			border: 0px solid green;
			width: 705px;
    margin: auto;
		}
		#formularioBuscador #formulario {
			text-align:left;
		}
		
		#formularioBuscador #formulario input{
			width:700px;
			border-radius: 45px 44px 44px 44px;
			font-size:20px;
		}
		
		#resultsFind{
			padding-left:60px;
		}
		
		#resultsFind ul{
			list-style-type: none;
  			margin: 0px 0px 25px 0px;
  			padding: 0;
  			overflow: hidden;
		}
		#resultsFind ul li.fileIndex{
			font-size:20px;
			color:#808080;
		}
		#resultsFind ul li.fileName{
			font-size:30px;
			color:Blue;
		}
		#resultsFind ul li.fileContent{
			font-size:25px;
			color:#303030;
		}
    </style>
    <!--[if lte IE 6]>
    <style type="text/css">
        #container {
            height: 100%;
        }
    </style>
    <![endif]-->
</head>

<body>
    <div id="wrapper">
    <?php require_once("header.php"); ?>
    
    <div id="content">
    	<div id="logoBuscador">
    		<p>
  				<span style='color: blue'>F</span>
  				<span style='color: red'>u</span>
  				<span style='color: yellow'>r</span>
  				<span style='color: blue'>g</span>
  				<span style='color: green'>R</span>
  				<span style='color: red'>I</span>
			</p>
		</div>
		<div id="formularioBuscador">
			<div id="formulario">
				<form action="pagerank.php" method="post">
					<lable>Alfa</lable><input type="text" name="alfa" id="alfa" value="0.1" alt="insira sua pesquisa" />
					<lable>Erro</lable><input type="text" name="erro" id="erro" value="0.01" alt="insira sua pesquisa" />
					<lable>Interações máxima</lable><input type="text" name="maxint" id="maxint" value="10" alt="insira sua pesquisa" />
					<input type="submit" value="Submit">
				</form>
			</div>
		</div>
		<div id="resultsFind">
		
		
<?php 

//campo de teleporte => probabilidade do usuário digitar diretamente a url
//print_r($_POST["alfa"]);
if (array_key_exists("alfa", $_POST) && !empty($_POST["alfa"])) {





$data_array =  array(
);
$make_call = callAPI('GET', 'http://localhost:8081/pagerank/pages', json_encode($data_array));
$pages = json_decode($make_call, true);
$make_call = callAPI('GET', 'http://localhost:8081/pagerank/relationList', json_encode($data_array));
$relation = json_decode($make_call, true);
//echo "<pre>";
//print_r($relation);
//echo "</pre>";

$linhaValores = "";

$tabela = "<table>";
$tabela .= "<tr><td></td>";
foreach($pages as $chave => $page){
	$celula = "<td>".$page["link"]."</td>";
	$tabela .= $celula;
	$linhaValores .= "<tr>$celula";
	foreach($pages as $page2){
		$value = 0;
		foreach($relation[$chave]["relations"] as $rel){
			if($rel["link"] == $page2["link"]) $value = 1;
		}
		$linhaValores .= "<td><center>$value</center></td>";
	}
	$linhaValores .= "</tr>";
}
$tabela .= "</tr>$linhaValores";
$tabela .= "</table>";

echo $tabela;

$teleport = $_POST["alfa"];
$erroAceitavel = $_POST["erro"];
$nroInteracoesMaximas = $_POST["maxint"];
$quantidade = count($pages);

//CALCULANDO PAGERANK
foreach($pages as $chave => $page){
	$pages[$chave]["apontaPara"] = count($relation[$chave]["relations"]); //adjacencias
	$contador = 0;
	//incidências
	foreach($relation as $chave2 => $rel){
		foreach($rel["relations"] as $rel2){
			if($rel2["link"] == $page["link"]) {
				$pages[$chave]["apontadores"][$chave2] = $chave2;
				$contador++;
			}
		}
	}
	$pages[$chave]["apontadoPor"] = $contador;
	$pages[$chave]["pagerank"] = 1/$quantidade;
}

$erroInteracao = $erroAceitavel+1;
while($erroInteracao > $erroAceitavel && $nroInteracoesMaximas > 0){
	$erroInteracao = 0;
	foreach($pages as $chave => $page){ 
		$somatorio = 0;
		foreach($pages[$chave]["apontadores"] as $chaveApontador){
			$somatorio += $pages[$chaveApontador]["pagerank"] / $pages[$chaveApontador]["apontaPara"];
		}
		$pageRankAnterior = $pages[$chave]["pagerank"];
		$pages[$chave]["pagerank"] = ($teleport/$quantidade) + (1 - $teleport)*$somatorio;
		$erro = abs($pageRankAnterior - $pages[$chave]["pagerank"]);
		$erroInteracao = ($erro > $erroInteracao) ? $erro : $erroInteracao;
	}
	$nroInteracoesMaximas--;
}

//echo "<pre>";
//print_r($pages);
//echo "</pre>";

foreach ($pages as $page) {
        echo "<ul class='result'>
				<li class='fileIndex'>{$page["pagerank"]}</li>
				<li class='fileName'>{$page["link"]}</li>
			</ul>";
	
}


 }
 
 
?>
		
	
		</div>
    </div>
    
    </div>
</body>



