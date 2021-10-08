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
    <div id="header" >
    	<ul class="horizontalMenu">
  			<li><a href="#">Home</a></li>
  			<li><a href="#">Menu 2</a></li>
  			<li><a href="#">Sobre</a></li>
		</ul>
    </div>
    
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
				<form action="teste.php" method="post">
					<input type="text" name="query" id="query" value="" alt="insira sua pesquisa" />
				</form>
			</div>
		</div>
		<div id="resultsFind">
		
		
<?php 

if (array_key_exists("query", $_POST) && !empty($_POST["query"])) {


function callAPI($method, $url, $data){
   $curl = curl_init();
   switch ($method){
      case "POST":
         curl_setopt($curl, CURLOPT_POST, 1);
         if ($data)
            curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
         break;
      case "PUT":
         curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "PUT");
         if ($data)
            curl_setopt($curl, CURLOPT_POSTFIELDS, $data);			 					
         break;
      default:
         if ($data)
            $url = sprintf("%s?%s", $url, http_build_query($data));
   }
   // OPTIONS:
   curl_setopt($curl, CURLOPT_URL, $url);
   curl_setopt($curl, CURLOPT_HTTPHEADER, array(
      //'APIKEY: 111111111111111111111',
      'Content-Type: application/json',
   ));
   curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
   curl_setopt($curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
   // EXECUTE:
   $result = curl_exec($curl);
   if(!$result){die("Connection Failure");}
   curl_close($curl);
   return $result;
}


$data_array =  array(
      "query"        => $_POST["query"]
);
$make_call = callAPI('POST', 'http://localhost:8081/consult/find', json_encode($data_array));
$response = json_decode($make_call, true);
//echo "<pre>";
//print_r($response);
// echo "</pre>";
 
 $ordered = $response["listVetorialModel"];
 usort($ordered, function($a, $b) {
    return $a['index'] < $b['index'];
});

//echo "<pre>";
//print_r($ordered);
// echo "</pre>";

foreach ($ordered as $value) {
	if($value["index"] > 0){
        echo "<ul class='result'>
				<li class='fileIndex'>{$value["index"]}</li>
				<li class='fileName'>{$value["file"]["name"]}</li>
				<li class='fileContent'>{$value["file"]["content"]}</li>
			</ul>";
	}
}


}


//error_reporting(-1);
//ini_set('display_errors', 'On');


//curl -X POST "http://localhost:8081/consult/find" -H  "accept: */*" -H  "Content-Type: application/json" -d "{\"query\":\"boi cavalo peão boi\"}"
?>
		
	
		</div>
    </div>
    
    </div>
</body>



