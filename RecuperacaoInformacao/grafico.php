<script>
window.onload = function () {

var chart = new CanvasJS.Chart("chartContainer", {
	animationEnabled: true,
	theme: "light2",
	title:{
		text: "Curva Recall Precision"
	},
	axisX:{
		title: "Recall",
		includeZero: true,
		crosshair: {
			enabled: true
		}
	},
	axisY: {
		title: "Precision",
		includeZero: true,
		crosshair: {
			enabled: true
		}
	},
	toolTip:{
		shared:true
	},  
	legend:{
		cursor:"pointer",
		verticalAlign: "bottom",
		horizontalAlign: "left",
		dockInsidePlotArea: true,
		itemclick: toogleDataSeries
	},
	data: [{
		type: "line",
		showInLegend: true,
		name: "Interpolada 11 pts",
		markerType: "square",
		color: "#F08080",
		dataPoints: [
<?php 
	$pontos = array();
	foreach($interpolada_11 as $chave => $valor){
		$pontos[] = "{ x: $chave, y: $valor }";
	}
	echo implode(",",$pontos);
?>
		
		]
	},
	{
		type: "line",
		showInLegend: true,
		name: "Completa",
		lineDashType: "dash",
		dataPoints: [
<?php 
	$pontos = array("{ x: 0, y: 100 }");
	foreach($arquivos as $chave => $valor){
		$pontos[] = "{ x: ".$arquivos[$chave]["completa"]["recall"].", y: ".$arquivos[$chave]["completa"]["precision"]." }";
	}
	echo implode(",",$pontos);
?>
		]
	},
	{
		type: "line",
		showInLegend: true,
		name: "Interpolada",
		lineDashType: "longDash",
		markerType: "triangle",
		color: "#228bb0",
		dataPoints: [
<?php 
	$pontos = array("{ x: 0, y: 100 }");
	foreach($arquivos as $chave => $valor){
		$pontos[] = "{ x: ".$arquivos[$chave]["interpolada"]["recall"].", y: ".$arquivos[$chave]["interpolada"]["precision"]." }";
	}
	echo implode(",",$pontos);
?>
		]
	}]
});
chart.render();

function toogleDataSeries(e){
	if (typeof(e.dataSeries.visible) === "undefined" || e.dataSeries.visible) {
		e.dataSeries.visible = false;
	} else{
		e.dataSeries.visible = true;
	}
	chart.render();
}

}
</script>

<div id="chartContainer" style="height: 700px; width: 700px;"></div>
<script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
