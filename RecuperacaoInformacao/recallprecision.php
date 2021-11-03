<?php 
error_reporting(-1);
ini_set('display_errors', 'On');
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
				<form action="recallprecision.php" method="post">
<?php
echo "<table border='0'><tr>";
for($i = 0; $i<21; $i++){
	if($i%3 == 0){echo "</tr><tr>";}
	echo "<td><label for = \"coding\"> Arquivo $i </ label></td>
		  <td> <input style='width: 50px;' type = \"checkbox\" id = \"arquivo$i\" name = \"arquivos[]\" value = \"arquivo$i\"> </td>";
}
echo "</tr></table>";

echo "<input type=\"hidden\" name=\"qtd_arquivos\" value=\"20\"  />";

?>
<input type="submit" value="Submit">
				</form>
			</div>
		</div>
		<div id="resultsFind">
		
		
<?php 

if (array_key_exists("qtd_arquivos", $_POST) && !empty($_POST["qtd_arquivos"])) {



//echo "<pre>";
//print_r($_POST);
// echo "</pre>";
 
 $arquivos = [];
 $qtd_relevantes = count($_POST["arquivos"]);
 
 $index_fake = 21;
 
 for($i = 0; $i<20; $i++){
	$arquivos["arquivo$i"]["index"] = $index_fake--;//random_int(0, 999);
	$arquivos["arquivo$i"]["marcado"] = (in_array("arquivo$i", $_POST["arquivos"])) ? "S" : "N";
}

usort($arquivos, function($a, $b) {
    return $a['index'] < $b['index'];
});

$contador = 1;
$contador_relevante = 0;
foreach($arquivos as $chave => $valor){
	$arquivos[$chave]["posicao"] = $contador;
	$arquivos[$chave]["qtd_relevante"] = ($arquivos[$chave]["marcado"] == "S") ? ++$contador_relevante : $contador_relevante;
	$arquivos[$chave]["precision"] = ($arquivos[$chave]["marcado"] == "S") ? round($arquivos[$chave]["qtd_relevante"]/$arquivos[$chave]["posicao"],2)*100 : 0;
	$arquivos[$chave]["completa"]["recall"] = round($arquivos[$chave]["qtd_relevante"]/$qtd_relevantes,2)*100;
	$arquivos[$chave]["completa"]["precision"] = round($arquivos[$chave]["qtd_relevante"]/$arquivos[$chave]["posicao"],2)*100;
	$arquivos[$chave]["interpolada"]["recall"] = round($arquivos[$chave]["qtd_relevante"]/$qtd_relevantes,2)*100;
	$arquivos[$chave]["interpolada"]["precision"] = 0;
	$contador++;
}

//precision interpolada
$i = 0;
foreach($arquivos as $chave2 => $valor2){
	$sub = array_slice($arquivos, $i, count($arquivos)-$i, true);
	$max = 0;
	foreach($sub  as $chave => $valor){
		$max = ($arquivos[$chave]["completa"]["precision"] > $max) ? $arquivos[$chave]["completa"]["precision"] : $max;
	}
	$arquivos[$chave2]["interpolada"]["precision"] = $max;
	$i++;
}

//interpolada 11 pontos
$interpolada_11 = array(0 => 100, 10 => 0, 20 => 0, 30 => 0, 40 => 0, 50 => 0, 60 => 0, 70 => 0, 80 => 0, 90 => 0, 100 => 0);
foreach($interpolada_11 as $chave => $valor){
	if($chave != 0){
		foreach($arquivos as $chave2 => $valor2){
			if($arquivos[$chave2]["interpolada"]["recall"] > $chave){
				$interpolada_11[$chave] = $arquivos[$chave2]["interpolada"]["precision"];
				break;
			}
		}
	}
}

//print_r($interpolada_11);


 

//echo $qtd_relevantes;
//echo "<pre>";
//print_r($arquivos);
// echo "</pre>";

require_once("grafico.php");

}





//curl -X POST "http://localhost:8081/consult/find" -H  "accept: */*" -H  "Content-Type: application/json" -d "{\"query\":\"boi cavalo peão boi\"}"
?>
		
	
		</div>
    </div>
    
    </div>
</body>



