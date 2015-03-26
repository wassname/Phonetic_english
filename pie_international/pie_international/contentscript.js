if (document.getElementById("cherry-pie"))
	webFontsReady=true;

setupCherryPieIfNot();

documentReady=true; // initWebFonts has set up web font css declarations
//console.log("documentReady. tryInitialize...");
tryInitialize();

