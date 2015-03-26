var documentID=Math.floor(Math.random()*0x100000000);
var pieEnabled=0;
var urlAllowed=false;
var langAllowed=false;
var fontSeq="";
var pieMode=3; // default to Lite
var nodeArrMap={};
var nextArrayKey=0;
var delayedTrans=[];
var observer=null;
var webFontsReady=false;
var langReady=false;
var pieStatusReady=false;
var documentReady=false;
var initialPieEnabled=null;
var initialFontSeq=null;
var initialUrlAllowed=null;
var initialPieMode=null;
var initialized=false;
var nRetryGetPieStatus=0;

var uncombineMap={

	// silences

	"\u0226": "A",
	"\u0227": "a",
	"\u0243": "B",
	"\u0180": "b",
	"\u010a": "C",
	"\u010b": "c",
	"\u0110": "D",
	"\u0111": "d",
	"\u0116": "E",
	"\u0117": "e",
	"\u1e1e": "F",
	"\u1e1f": "f",
	"\u01e4": "G",
	"\u01e5": "g",
	"\u0126": "H",
	"\u0127": "h",
	"\u0268": "i",
	"\u0197": "I",
	"\u0248": "J",
	"\u0249": "j",
	"\ua740": "K",
	"\ua741": "k",
	"\u019a": "l",
	"\u023d": "L",
	"\u022e": "O",
	"\u022f": "o",
	"\u2c63": "P",
	"\u1d7d": "p",
	"\u1e56": "P",
	"\u1e57": "p",
	"\ua756": "Q",
	"\ua757": "q",
	"\u024c": "R",
	"\u024d": "r",
	"\u1e60": "S",
	"\u1e61": "s",
	"\u0166": "T",
	"\u0167": "t",
	"\u0244": "U",
	"\u0289": "u",
	"\u024e": "Y",
	"\u024f": "y",
	"\u01b5": "Z",
	"\u01b6": "z",

	// )

	"\u1e9a": "a",

	// stress

	"\u1ea0": "A",
	"\u1ea1": "a",
	"\u1eb8": "E",
	"\u1eb9": "e",
	"\u1eca": "I",
	"\u1ecb": "i",
	"\u1ecc": "O",
	"\u1ecd": "o",
	"\u1ee4": "U",
	"\u1ee5": "u",
	"\u1e88": "W",
	"\u1e89": "w",
	"\u1ef4": "Y",
	"\u1ef5": "y",
	"\u1e5a": "R",
	"\u1e5b": "r",

	// /

	"\u00c1": "A",
	"\u00e1": "a",
	"\u00c9": "E",
	"\u00e9": "e",
	"\u00cd": "I",
	"\u00ed": "i",
	"\u00d3": "O",
	"\u00f3": "o",
	"\u00da": "U",
	"\u00fa": "u",
	"\u00dd": "Y",
	"\u00fd": "y",

	// ^

	"\u00c2": "A",
	"\u00e2": "a",
	"\u00ca": "E",
	"\u00ea": "e",
	"\u00d4": "O",
	"\u00f4": "o",

	// u

	"\u0114": "E",
	"\u0115": "e",
	"\u014e": "O",
	"\u014f": "o",
	"\u016c": "U",
	"\u016d": "u",

	// -

	"\u0100": "A",
	"\u0101": "a",
	"\u0112": "E",
	"\u0113": "e",
	"\u1e20": "G",
	"\u1e21": "g",
	"\u012a": "I",
	"\u012b": "i",
	"\u014c": "O",
	"\u014d": "o",
	"\u016a": "U",
	"\u016b": "u",
	"\u0232": "Y",
	"\u0233": "y",

	// ..

	"\u00c4": "A",
	"\u00e4": "a",
	"\u00cb": "E",
	"\u00eb": "e",
	"\u00cf": "I",
	"\u00ef": "i",
	"\u00d6": "O",
	"\u00f6": "o",
	"\u00dc": "U",
	"\u00fc": "u",
	"\u1e84": "W",
	"\u1e85": "w",
	"\u0178": "Y",
	"\u00ff": "y",

	// \\

	"\u0200": "A",
	"\u0201": "a",
	"\u0204": "E",
	"\u0205": "e",
	"\u0214": "U",
	"\u0215": "u",

	// //

	"\u0150": "O",
	"\u0151": "o",

	// \

	"\u00c0": "A",
	"\u00e0": "a",
	"\u00c8": "E",
	"\u00e8": "e",
	"\u00cc": "I",
	"\u00ec": "i",
	"\u00d2": "O",
	"\u00f2": "o",
	"\u00d9": "U",
	"\u00f9": "u",
	"\u1e80": "W",
	"\u1e81": "w",
	"\u1ef2": "Y",
	"\u1ef3": "y",

	// ) below

	"\u00c7": "C",
	"\u00e7": "c",
	"\u015e": "S",
	"\u015f": "s",
	"\u0162": "T",
	"\u0163": "t",

	// - below

	"\u1e6e": "T",
	"\u1e6f": "t",
	"\u1e94": "Z",
	"\u1e95": "z"
};

function allWebFontsLoaded()
{
	webFontsReady=true;
	if (!initialized)
		tryInitialize();
	else
		tryProcessDelayedTrans();
}

function transformNodes(arrayID, strArr, textNodeType)
{
	if (!nodeArrMap.hasOwnProperty(arrayID))
		return;

	setupCherryPieIfNot();
	if (!webFontsReady || !langReady) {
		if (!langReady && delayedTrans.length>100) {
			langReady=true;
			langAllowed=true;
			tryProcessDelayedTrans();
		}
		if (!webFontsReady || !langReady) {
			var obj={};
			obj.arrayID=arrayID;
			obj.strArr=strArr;
			obj.textNodeType=textNodeType;
			console.log("arrayID ", arrayID, " queued to delayedTrans because webFontsReady: ", webFontsReady, " langReady: ", langReady);
			delayedTrans.push(obj);
			return;
		}
	}

	if (pieEnabled==0 || urlAllowed==false || langAllowed==false) {
		delete nodeArrMap[arrayID];
		return;
	}

	establishGlobalFont();

	var summaries=observer.disconnect();
	if (summaries)
		handleChanges(summaries);

	var nodeArr=nodeArrMap[arrayID];
	if (textNodeType==0) { // text nodes
		for (var i=0; i<nodeArr.length; i++) {
			if (strArr[i]==null)
				continue;
			if (nodeArr[i] && nodeArr[i].parentNode) {
				if (pieMode<=1 && strArr[i].charCodeAt(0)==65535) {
					var spacePos=strArr[i].lastIndexOf(" ");
					if (strArr[i].charCodeAt(1)==48) // "the/to/into/onto "+word
						nodeArr[i].nodeValue=strArr[i].substring(3, spacePos+1);
					else if (strArr[i].charCodeAt(1)==49) // "the/to/into/onto <quotation mark>"+word
						nodeArr[i].nodeValue=strArr[i].substring(3, spacePos+2);
					else // "the/to/into/onto"+space+word
						nodeArr[i].nodeValue=strArr[i].substring(3, spacePos);
				}
				else
					nodeArr[i].nodeValue=strArr[i];
			}
		}
	}
	else { // buttons
		for (var i=0; i<nodeArr.length; i++) {
			if (strArr[i]==null)
				continue;
			if (nodeArr[i] && nodeArr[i].parentNode)
				nodeArr[i].value=strArr[i];
		}
	}
	delete nodeArrMap[arrayID];
	observer.reconnect();
}

function isHidden(element)
{
	if (element.dataset.hidden)
		return element.dataset.hidden=="t";
	else if (element.classList.length==0 && element.style.display=="") {
		element.dataset.hidden="f";
		return false;
	}
	else {
		if (window.getComputedStyle(element).display=="none") {
			element.dataset.hidden="t";
			return true;
		}
		else {
			element.dataset.hidden="f";
			return false;
		}
	}
}

function addNodes(nodeArr, textNodeType, requestLang)
{
	var strings=[], worthy=0;

	if (textNodeType==0)
		for (var i=0; i<nodeArr.length; i++) {
			if (
				!nodeArr[i].parentNode
				|| nodeArr[i].parentNode.isContentEditable==true
				|| /^textarea$|^script$|^style$|^title$|^#cdata-section$|^#comment$|^option$/i.test(nodeArr[i].parentNode.nodeName)==true
				|| nodeArr[i].nodeType!=3 // not a text node
				|| /^\s*$|[\u0300-\u036f\u207a]|\{\{/.test(nodeArr[i].nodeValue)==true // all whitespaces, any diacritics, or "{{"
				|| /^gbqfs|^nopie|^collapseButton|^NavToggle/.test(nodeArr[i].parentNode.id)==true // google front page buttons, "Word Translator" UI elements, Wikipedia toggles
				|| (/^div$/i.test(nodeArr[i].parentNode.nodeName)==true && isHidden(nodeArr[i].parentNode))
			)
				strings.push(null);
			else {
				worthy=1;
				if (pieMode<=1 && /\b(the|to|into|onto) ?["'\u2018\u201c]?$/i.test(nodeArr[i].nodeValue)==true) {
					var match=nodeArr[i].nodeValue.match(/( ?)(["'\u2018\u201c]?$)/);
					if (match[1].length>0) { // has space
						if (nodeArr[i].nextSibling!=null && nodeArr[i].nextSibling.textContent!=null) {
							var match2=nodeArr[i].nextSibling.textContent.match(/^["'\u2018\u201c]?[a-zA-Z]+/);
							if (match2!=null) {
								if (match[2].length==0) // match has no quotation mark
									strings.push(["\uffff0 ", nodeArr[i].nodeValue, match2[0]].join(""));
								else // match has quotation mark
									strings.push(["\uffff1 ", nodeArr[i].nodeValue, match2[0]].join(""));
								continue;
							}
						}
					}
					else { // no space
						var node=nodeArr[i];
						var found=false;
						while (node.parentNode!=null) {
							node=node.parentNode;
							if (node.nextSibling!=null) {
								if (node.nextSibling.textContent!=null) {
									var match2=node.nextSibling.textContent.match(/^ [a-zA-Z]+/);
									if (match2!=null) {
										strings.push(["\uffff2 ", nodeArr[i].nodeValue, match2[0]].join(""));
										found=true;
									}
								}
								break;
							}
						}
						if (found)
							continue;
					}
				}
				strings.push(nodeArr[i].nodeValue);
			}
		}
	else
		for (var i=0; i<nodeArr.length; i++) {
			if (
				!nodeArr[i].parentNode
				|| nodeArr[i].isContentEditable==true
				|| /[\u0300-\u036f\u207a]/.test(nodeArr[i].value)==true
			)
				strings.push(null);
			else {
				strings.push(nodeArr[i].value);
				worthy=1;
			}
		}

	if (worthy) {
		nextArrayKey=(nextArrayKey+1)%999999999999;
		nodeArrMap[nextArrayKey]=nodeArr;
		console.log("ADD: arrayID: ", nextArrayKey, " Elements: ", Object.keys(nodeArrMap).length);
		chrome.extension.sendRequest({greeting: "pieTextArray", textNodeType: textNodeType, arrayID: nextArrayKey, strings: strings, requestLang: requestLang}, onResponse);
	}
	else {
		if (requestLang) {
			langReady=true;
			langAllowed=true;
		}
	}
}

function handleChanges(summaries)
{
	var summary;

	// text nodes
 	summary=summaries[0];
	if (summary.added.length>0)
		addNodes(summary.added, 0, false);
	if (summary.valueChanged.length>0)
		addNodes(summary.valueChanged, 0, false);

	// buttons
	summary=summaries[1];
	if (summary.added.length>0)
		addNodes(summary.added, 1, false);
	if (summary.attributeChanged.value.length>0)
		addNodes(summary.attributeChanged.value, 1, false);

	//console.log("dynamic change sent.");
}

function createInitialTextChanges()
{
	var textNodes=[], buttonNodes=[];

	//console.log("sending initial text changes...");

	if (document.body) {
		// initial text nodes
		var walker=document.createTreeWalker(document.body, NodeFilter.SHOW_TEXT, null, false);
		var node;
		while (node=walker.nextNode())
			textNodes.push(node);

		// initial buttons
		buttonNodes=document.body.querySelectorAll("input[type=submit],input[type=button],input[type=reset]");

		var requestLang=langReady?false:true;

		// text nodes
		if (textNodes.length>0)
			addNodes(textNodes, 0, requestLang);
		else {
			if (requestLang) {
				langReady=true;
				langAllowed=true;
			}
		}

		// buttons
		if (buttonNodes.length>0)
			addNodes(buttonNodes, 1, false);
	}
	else {
		console.log("document.body doesn't exist.");
	}
	//console.log("initial text changes sent.");
}

function restoreString(s)
{
	if (/[\u00b7\u2027]/.test(s)==true)
		s=s.replace(/([A-Za-z\u0300-\u036f\u0226\u0227\u0243\u0180\u010a\u010b\u0110\u0111\u0116\u0117\u1e1e\u1e1f\u01e4\u01e5\u0126\u0127\u0268\u0197\u0248\u0249\ua740\ua741\u019a\u023d\u022e\u022f\u2c63\u1d7d\u1e56\u1e57\ua756\ua757\u024c\u024d\u1e60\u1e61\u0166\u0167\u0244\u0289\u024e\u024f\u01b5\u01b6\u1ec8\u1ec9\u1ece\u1ecf\u1ea0\u1ea1\u1eb8\u1eb9\u1eca\u1ecb\u1ecc\u1ecd\u1ee4\u1ee5\u1e88\u1e89\u1ef4\u1ef5\u1e5a\u1e5b\u00c1\u00e1\u00c9\u00e9\u00cd\u00ed\u00d3\u00f3\u00da\u00fa\u00dd\u00fd\u00c5\u00e5\u0102\u0103\u0114\u0115\u014e\u014f\u0206\u0207\u020e\u020f\u0216\u0217\u0100\u0101\u0112\u0113\u1e20\u1e21\u012a\u012b\u014c\u014d\u016a\u016b\u0232\u0233\u00c4\u00e4\u00cb\u00eb\u00cf\u00ef\u00d6\u00f6\u00dc\u00fc\u1e84\u1e85\u0178\u00ff\u0200\u0201\u0204\u0205\u0214\u0215\u0150\u0151\u00c0\u00e0\u00c8\u00e8\u00cc\u00ec\u00d2\u00f2\u00d9\u00f9\u1e80\u1e81\u1ef2\u1ef3\u00c7\u00e7\u015e\u015f\u0162\u0163\u1e6e\u1e6f\u1e94\u1e95]+)[\u00b7\u2027]([A-Za-z\u0300-\u036f\u0226\u0227\u0243\u0180\u010a\u010b\u0110\u0111\u0116\u0117\u1e1e\u1e1f\u01e4\u01e5\u0126\u0127\u0268\u0197\u0248\u0249\ua740\ua741\u019a\u023d\u022e\u022f\u2c63\u1d7d\u1e56\u1e57\ua756\ua757\u024c\u024d\u1e60\u1e61\u0166\u0167\u0244\u0289\u024e\u024f\u01b5\u01b6\u1ec8\u1ec9\u1ece\u1ecf\u1ea0\u1ea1\u1eb8\u1eb9\u1eca\u1ecb\u1ecc\u1ecd\u1ee4\u1ee5\u1e88\u1e89\u1ef4\u1ef5\u1e5a\u1e5b\u00c1\u00e1\u00c9\u00e9\u00cd\u00ed\u00d3\u00f3\u00da\u00fa\u00dd\u00fd\u00c5\u00e5\u0102\u0103\u0114\u0115\u014e\u014f\u0206\u0207\u020e\u020f\u0216\u0217\u0100\u0101\u0112\u0113\u1e20\u1e21\u012a\u012b\u014c\u014d\u016a\u016b\u0232\u0233\u00c4\u00e4\u00cb\u00eb\u00cf\u00ef\u00d6\u00f6\u00dc\u00fc\u1e84\u1e85\u0178\u00ff\u0200\u0201\u0204\u0205\u0214\u0215\u0150\u0151\u00c0\u00e0\u00c8\u00e8\u00cc\u00ec\u00d2\u00f2\u00d9\u00f9\u1e80\u1e81\u1ef2\u1ef3\u00c7\u00e7\u015e\u015f\u0162\u0163\u1e6e\u1e6f\u1e94\u1e95]+)/g, function (str, p1, p2) {
			if (/[\u0300-\u036f\u0226\u0227\u0243\u0180\u010a\u010b\u0110\u0111\u0116\u0117\u1e1e\u1e1f\u01e4\u01e5\u0126\u0127\u0268\u0197\u0248\u0249\ua740\ua741\u019a\u023d\u022e\u022f\u2c63\u1d7d\u1e56\u1e57\ua756\ua757\u024c\u024d\u1e60\u1e61\u0166\u0167\u0244\u0289\u024e\u024f\u01b5\u01b6\u1ec8\u1ec9\u1ece\u1ecf\u1ea0\u1ea1\u1eb8\u1eb9\u1eca\u1ecb\u1ecc\u1ecd\u1ee4\u1ee5\u1e88\u1e89\u1ef4\u1ef5\u1e5a\u1e5b\u00c1\u00e1\u00c9\u00e9\u00cd\u00ed\u00d3\u00f3\u00da\u00fa\u00dd\u00fd\u00c5\u00e5\u0102\u0103\u0114\u0115\u014e\u014f\u0206\u0207\u020e\u020f\u0216\u0217\u0100\u0101\u0112\u0113\u1e20\u1e21\u012a\u012b\u014c\u014d\u016a\u016b\u0232\u0233\u00c4\u00e4\u00cb\u00eb\u00cf\u00ef\u00d6\u00f6\u00dc\u00fc\u1e84\u1e85\u0178\u00ff\u0200\u0201\u0204\u0205\u0214\u0215\u0150\u0151\u00c0\u00e0\u00c8\u00e8\u00cc\u00ec\u00d2\u00f2\u00d9\u00f9\u1e80\u1e81\u1ef2\u1ef3\u00c7\u00e7\u015e\u015f\u0162\u0163\u1e6e\u1e6f\u1e94\u1e95]/.test(p1)==true || /[\u0300-\u036f\u0226\u0227\u0243\u0180\u010a\u010b\u0110\u0111\u0116\u0117\u1e1e\u1e1f\u01e4\u01e5\u0126\u0127\u0268\u0197\u0248\u0249\ua740\ua741\u019a\u023d\u022e\u022f\u2c63\u1d7d\u1e56\u1e57\ua756\ua757\u024c\u024d\u1e60\u1e61\u0166\u0167\u0244\u0289\u024e\u024f\u01b5\u01b6\u1ec8\u1ec9\u1ece\u1ecf\u1ea0\u1ea1\u1eb8\u1eb9\u1eca\u1ecb\u1ecc\u1ecd\u1ee4\u1ee5\u1e88\u1e89\u1ef4\u1ef5\u1e5a\u1e5b\u00c1\u00e1\u00c9\u00e9\u00cd\u00ed\u00d3\u00f3\u00da\u00fa\u00dd\u00fd\u00c5\u00e5\u0102\u0103\u0114\u0115\u014e\u014f\u0206\u0207\u020e\u020f\u0216\u0217\u0100\u0101\u0112\u0113\u1e20\u1e21\u012a\u012b\u014c\u014d\u016a\u016b\u0232\u0233\u00c4\u00e4\u00cb\u00eb\u00cf\u00ef\u00d6\u00f6\u00dc\u00fc\u1e84\u1e85\u0178\u00ff\u0200\u0201\u0204\u0205\u0214\u0215\u0150\u0151\u00c0\u00e0\u00c8\u00e8\u00cc\u00ec\u00d2\u00f2\u00d9\u00f9\u1e80\u1e81\u1ef2\u1ef3\u00c7\u00e7\u015e\u015f\u0162\u0163\u1e6e\u1e6f\u1e94\u1e95]/.test(p2)==true)
				return p1+p2;
			else
				return str;
		});

	s=s.replace(/[\u0300-\u036f\u207a]+/g, ""); // remove all combining diacritics and superscript plus sign
	s=s.replace(/\u0226|\u0227|\u0243|\u0180|\u010a|\u010b|\u0110|\u0111|\u0116|\u0117|\u1e1e|\u1e1f|\u01e4|\u01e5|\u0126|\u0127|\u0268|\u0197|\u0248|\u0249|\ua740|\ua741|\u019a|\u023d|\u022e|\u022f|\u2c63|\u1d7d|\u1e56|\u1e57|\ua756|\ua757|\u024c|\u024d|\u1e60|\u1e61|\u0166|\u0167|\u0244|\u0289|\u024e|\u024f|\u01b5|\u01b6|\u1e9a|\u1ea0|\u1ea1|\u1eb8|\u1eb9|\u1eca|\u1ecb|\u1ecc|\u1ecd|\u1ee4|\u1ee5|\u1e88|\u1e89|\u1ef4|\u1ef5|\u1e5a|\u1e5b|\u00c1|\u00e1|\u00c9|\u00e9|\u00cd|\u00ed|\u00d3|\u00f3|\u00da|\u00fa|\u00dd|\u00fd|\u00c2|\u00e2|\u00ca|\u00ea|\u00d4|\u00f4|\u0114|\u0115|\u014e|\u014f|\u016c|\u016d|\u0100|\u0101|\u0112|\u0113|\u1e20|\u1e21|\u012a|\u012b|\u014c|\u014d|\u016a|\u016b|\u0232|\u0233|\u00c4|\u00e4|\u00cb|\u00eb|\u00cf|\u00ef|\u00d6|\u00f6|\u00dc|\u00fc|\u1e84|\u1e85|\u0178|\u00ff|\u0200|\u0201|\u0204|\u0205|\u0214|\u0215|\u0150|\u0151|\u00c0|\u00e0|\u00c8|\u00e8|\u00cc|\u00ec|\u00d2|\u00f2|\u00d9|\u00f9|\u1e80|\u1e81|\u1ef2|\u1ef3|\u00c7|\u00e7|\u015e|\u015f|\u0162|\u0163|\u1e6e|\u1e6f|\u1e94|\u1e95/g, function(c) {
		return uncombineMap[c];
	}); // revert precomposed letters to base letters
	return s;
}

function restorePage()
{
	if (document.body) {
		// existing text nodes
		var walker=document.createTreeWalker(document.body, NodeFilter.SHOW_TEXT, null, false);
		var node;
		while (node=walker.nextNode()) {
			if (
				node.parentNode
				&& node.parentNode.isContentEditable==false
				&& /^textarea$|^script$|^style$|^title$|^#cdata-section$|^#comment$|^option$/i.test(node.parentNode.nodeName)==false
				&& node.nodeType==3 // is a text node
				&& /^\s*$/.test(node.nodeValue)==false
				&& /^gbqfs|^nopie|^collapseButton|^NavToggle/.test(node.parentNode.id)==false // not google front page buttons, "Word Translator" UI elements, Wikipedia toggles
				&& (/^div$/i.test(node.parentNode.nodeName)==false || isHidden(node.parentNode)==false)
			) {
				node.nodeValue=restoreString(node.nodeValue);
			}
		}

		// existing buttons
		var nodeList=document.body.querySelectorAll("input[type=submit],input[type=button],input[type=reset]");
		for (var i=0; i<nodeList.length; i++) {
			if (
				nodeList[i].parentNode
				&& nodeList[i].isContentEditable==false
			) {
				nodeList[i].value=restoreString(nodeList[i].value);
			}
		}
	}
	else {
		console.log("restorePage: document.body doesn't exist.");
	}
}

function setupCherryPieIfNot()
{
	// set up web font Cherry PIE
	var style=document.getElementById("cherry-pie");
	if (!style && document.head) {
		style=document.createElement('style');
		style.id="cherry-pie";
		style.innerHTML=
			"@font-face { font-family: 'Cherry PIE'; src: local('☺'), url('"+chrome.extension.getURL("/fonts/CherryPIE-R.woff")+"') format('woff'); }\n"+
			"@font-face { font-family: 'Cherry PIE'; font-style: italic; src: local('☺'), url('"+chrome.extension.getURL("/fonts/CherryPIE-I.woff")+"') format('woff'); }\n"+
			"@font-face { font-family: 'Cherry PIE'; font-weight: bold; src: local('☺'), url('"+chrome.extension.getURL("/fonts/CherryPIE-B.woff")+"') format('woff'); }\n"+
			"@font-face { font-family: 'Cherry PIE'; font-weight: bold; font-style: italic; src: local('☺'), url('"+chrome.extension.getURL("/fonts/CherryPIE-BI.woff")+"') format('woff'); }\n";
		document.head.appendChild(style);
		
		if (initialized) {
			if (!webFontsReady)
				return;
			if (isFontLocal(fontSeq))
				return;
		}
		
		webFontsReady=false;
		initWebFonts();
	}
}
	
function establishGlobalFont()
{
	var style=document.getElementById("pie-font");
	if (!style && document.head) {
		style=document.createElement('style');
		style.id="pie-font";
		style.innerHTML=":not(textarea):not(input):not([contenteditable='plaintext-only']):not(#asdfg), input[type]:not([type='text']):not(#asdfg) { font-family: "+fontSeq+" !important; font-variant: normal !important; }";
		document.head.appendChild(style);
	}
}

function abolishGlobalFont()
{
	var style=document.getElementById("pie-font");
	if (style && document.head)
		document.head.removeChild(style);
}

function changeGlobalFont(newFont)
{
	fontSeq=newFont;
	var style=document.getElementById("pie-font");
	if (style) {
		style.innerHTML=":not(textarea):not(input):not([contenteditable='plaintext-only']):not(#asdfg), input[type]:not([type='text']):not(#asdfg) { font-family: "+fontSeq+" !important; font-variant: normal !important; }";
	}
}

function enablePIE()
{
	if (observer==null) {
		observer = new MutationSummary({
			rootNode: document.body,
			callback: handleChanges,
			queries: [
				{characterData: true},
				{element: "input[type='button'],input[type='submit'],input[type='reset']", elementAttributes: "value"}
			]
		});
	}
	else
		observer.reconnect();

	createInitialTextChanges();
}

function disablePIE()
{
	if (observer!=null) {
		observer.disconnect();
		observer=null;
		nodeArrMap={};
		delayedTrans={};
		restorePage();
		abolishGlobalFont();
	}
}

function setEnabled(isEnabled)
{
	if (pieEnabled==isEnabled)
		return;

	pieEnabled=isEnabled;
	if (pieEnabled && urlAllowed && (langAllowed || !langReady))
		enablePIE();
	else
		disablePIE();
}

function handleRequest(request, sender, sendResponse)
{
	if (!sender.tabs) { // from extension
		if (request.greeting=="pieTellEnabled") { // extension requests to enable/disable PIE
			if (initialized)
				setEnabled(request.toEnable);
			else {
				initialPieEnabled=request.toEnable;
				//console.log("by extension request, initialPieEnabled reset to ", initialPieEnabled);
			}
		}
		else if (request.greeting=="pieNewOptions") { // extension asks to apply new options
			if (initialized) {
				changeGlobalFont(request.newOptions.fontSeq);
				urlAllowed=request.newOptions.urlAllowed;
				pieMode=request.newOptions.pieMode;
				if (pieEnabled==1) {
					disablePIE();
					langReady=false; langAllowed=false;
					if (urlAllowed)
						enablePIE();
				}
			}
			else {
				initialFontSeq=request.newOptions.fontSeq;
				initialUrlAllowed=request.newOptions.urlAllowed;
				initialPieMode=request.newOptions.pieMode;
				isFontLocal(initialFontSeq);
				//console.log("by extension request, initialFontSeq reset to ", initialFontSeq);
				//console.log("by extension request, initialUrlAllowed reset to ", initialUrlAllowed);
			}
		}
		else if (request.greeting=="pieGetSelection") { // extension asks for context menu document's selection
			if (request.documentID==documentID)
				sendResponse({greeting: "pieSelection", text: restoreString(window.getSelection().toString())});
		}
	}
}

function tryProcessDelayedTrans()
{
	if (webFontsReady && langReady) {
		if (delayedTrans.length>0) {
			console.log("Processing delayedTrans: ", delayedTrans);
			for (var i=0; i<delayedTrans.length; i++)
				transformNodes(
					delayedTrans[i].arrayID,
					delayedTrans[i].strArr,
					delayedTrans[i].textNodeType
				);
			delayedTrans=[];
		}
	}
}

function tryInitialize()
{
	if (initialized)
		return;

	if (pieStatusReady && documentReady && webFontsReady) {

/*
		console.log("tryInitialize succeeded. pieStatusReady && documentReady && webFontsReady.");
		console.log("    initialPieEnabled: ", initialPieEnabled);
		console.log("    initialFontSeq: ", initialFontSeq);
		console.log("    initialUrlAllowed: ", initialUrlAllowed);
*/

		fontSeq=initialFontSeq;
		urlAllowed=initialUrlAllowed;
		pieMode=initialPieMode;

		initialized=true;
		setEnabled(initialPieEnabled);
	}
}

function isFontLocal(font)
{
	var ntVer=/Windows NT [0-9]+\./.exec(navigator.userAgent);
	if (ntVer!=null && parseInt(/[0-9]+/.exec(ntVer))>=6) { // Windows Vista or higher
		if (font.indexOf("Cambria")>=0 && font.indexOf("Cherry PIE")<0) {
			// Cambria will be used; we won't wait for Cherry PIE to load
			allWebFontsLoaded();
			return true;
		}
	}
	return false;
}

function onResponse(response)
{
	if (!response) {
		if (!pieStatusReady) { // failed to get pie status because extension not ready. try again later.
			nRetryGetPieStatus++;
			if (nRetryGetPieStatus<=20) {
				//console.log("failed to get pie status. retry ", nRetryGetPieStatus);
				setTimeout(requestPieStatus, 1000);
			}
			return;
		}
		setEnabled(0);
		return;
	}

	if (response.greeting=="piePieTextArray") { // extension returns PIE string array for text nodes or button nodes
		if (response.langInfo>0) {
			langReady=true;
			langAllowed=(response.langInfo==1)?true:false;
			transformNodes(response.arrayID, response.strings, response.textNodeType);
			tryProcessDelayedTrans();
		}
		else
			transformNodes(response.arrayID, response.strings, response.textNodeType);
	}
	else if (response.greeting=="pieTellOptions") { // extension returns PIE status
		if (initialPieEnabled==null) {
			initialPieEnabled=response.isEnabled;
			//console.log("by extension response, initialPieEnabled set from null to ", initialPieEnabled);
		}
		if (initialUrlAllowed==null) {
			initialUrlAllowed=response.urlAllowed;
			//console.log("by extension response, initialUrlAllowed set from null to ", initialUrlAllowed);
		}
		if (initialPieMode==null) {
			initialPieMode=response.pieMode;
		}
		if (initialFontSeq==null) {
			initialFontSeq=response.fontSeq;
			//console.log("by extension response, initialFontSeq set from null to ", initialFontSeq);
		}

		console.log("pieStatusReady. tryInitialize...");
		pieStatusReady=true;
		tryInitialize();

		isFontLocal(initialFontSeq); // this checks if font is Cambria which would lead to webFontsReady and tryInitialize
	}
}

function requestPieStatus()
{
	chrome.extension.sendRequest({greeting: "pieStatusRequest"}, onResponse); // request PIE status from extension
}

function initWebFonts()
{
	if (webFontsReady) {
		console.log("webFontsReady already true before font load test. test aborted.");
		return;
	}

	if (document.body==null || document.body.isContentEditable==true) { // if document body can't accept test nodes
		allWebFontsLoaded();
		return;
	}

	// set up test nodes

	function createTestNode(fontString, styleString)
	{
		var span=document.createElement('span');
		span.innerHTML='BESbswy';
		span.setAttribute("style", styleString+"font-family:"+fontString+";");
		document.body.appendChild(span);
		return span;
	}

	function removeTestNode(node)
	{
		if (node && node.parentNode)
			node.parentNode.removeChild(node);
	}

	var commonStyleString="position:absolute;top:-999px;left:-999px;"+
		"font-size:300px;width:auto;height:auto;line-height:normal;margin:0;"+
		"padding:0;font-variant:normal;";

	var originalFontString="arial,'URW Gothic L',sans-serif";

	var originalFontNodeR=createTestNode(originalFontString, commonStyleString+
		"font-style:normal;font-weight:normal;");
	var originalFontNodeI=createTestNode(originalFontString, commonStyleString+
		"font-style:italic;font-weight:normal;");
	var originalFontNodeB=createTestNode(originalFontString, commonStyleString+
		"font-style:normal;font-weight:bold;");
	var originalFontNodeBI=createTestNode(originalFontString, commonStyleString+
		"font-style:italic;font-weight:bold;");

	var originalFontWidthR=originalFontNodeR.offsetWidth;
	var originalFontWidthI=originalFontNodeI.offsetWidth;
	var originalFontWidthB=originalFontNodeB.offsetWidth;
	var originalFontWidthBI=originalFontNodeBI.offsetWidth;

	var lastFontWidthR=originalFontWidthR;
	var lastFontWidthI=originalFontWidthI;
	var lastFontWidthB=originalFontWidthB;
	var lastFontWidthBI=originalFontWidthBI;

/*
	console.log("originalFontNodeR: ", originalFontNodeR.outerHTML, " originalFontWidthR: ", originalFontWidthR);
	console.log("");
	console.log("originalFontNodeI: ", originalFontNodeI.outerHTML, " originalFontWidthI: ", originalFontWidthI);
	console.log("");
	console.log("originalFontNodeB: ", originalFontNodeB.outerHTML, " originalFontWidthB: ", originalFontWidthB);
	console.log("");
	console.log("originalFontNodeBI: ", originalFontNodeBI.outerHTML, " originalFontWidthBI: ", originalFontWidthBI);
	console.log("");

	console.log("");
*/

	removeTestNode(originalFontNodeR);
	removeTestNode(originalFontNodeI);
	removeTestNode(originalFontNodeB);
	removeTestNode(originalFontNodeBI);

	var webFontString="'Cherry PIE',"+originalFontString;

	var webFontNodeR=createTestNode(webFontString, commonStyleString+
		"font-style:normal;font-weight:normal;");
	var webFontNodeI=createTestNode(webFontString, commonStyleString+
		"font-style:italic;font-weight:normal;");
	var webFontNodeB=createTestNode(webFontString, commonStyleString+
		"font-style:normal;font-weight:bold;");
	var webFontNodeBI=createTestNode(webFontString, commonStyleString+
		"font-style:italic;font-weight:bold;");

/*
	console.log("webFontNodeR: ", webFontNodeR.outerHTML, "immediate webFontWidthR: ", webFontNodeR.offsetWidth);
	console.log("");
	console.log("webFontNodeI: ", webFontNodeI.outerHTML, "immediate webFontWidthI: ", webFontNodeI.offsetWidth);
	console.log("");
	console.log("webFontNodeB: ", webFontNodeB.outerHTML, "immediate webFontWidthB: ", webFontNodeB.offsetWidth);
	console.log("");
	console.log("webFontNodeBI: ", webFontNodeBI.outerHTML, "immediate webFontWidthBI: ", webFontNodeBI.offsetWidth);
	console.log("");

	console.log("");
*/

	var webFontReadyR=false, webFontReadyI=false, webFontReadyB=false, webFontReadyBI=false;
	var loadedFonts=0;

	function removeWebFontNodes()
	{
		removeTestNode(webFontNodeR);
		removeTestNode(webFontNodeI);
		removeTestNode(webFontNodeB);
		removeTestNode(webFontNodeBI);
	}

	function checkWebFontNode(node, origWidth, lastWidth)
	{
		if (!node)
			return {ready: true, newWidth: lastWidth};

		var newWidth=node.offsetWidth;
		if (newWidth!=origWidth && newWidth==lastWidth) {
			loadedFonts++;
			//console.log("new web font ready.");
			return {ready: true, newWidth: newWidth};
		}

		return {ready: false, newWidth: newWidth};
	}

	function waitForFonts(tryCount)
	{
		if (webFontsReady) {
			removeWebFontNodes();
			return;
		}

		var result;

		if (!webFontReadyR) {
			result=checkWebFontNode(webFontNodeR, originalFontWidthR, lastFontWidthR);
			webFontReadyR=result.ready;
			lastFontWidthR=result.newWidth;
		}
		if (!webFontReadyI) {
			result=checkWebFontNode(webFontNodeI, originalFontWidthI, lastFontWidthI);
			webFontReadyI=result.ready;
			lastFontWidthI=result.newWidth;
		}
		if (!webFontReadyB) {
			result=checkWebFontNode(webFontNodeB, originalFontWidthB, lastFontWidthB);
			webFontReadyB=result.ready;
			lastFontWidthB=result.newWidth;
		}
		if (!webFontReadyBI) {
			result=checkWebFontNode(webFontNodeBI, originalFontWidthBI, lastFontWidthBI);
			webFontReadyBI=result.ready;
			lastFontWidthBI=result.newWidth;
		}

		tryCount++;
		if (loadedFonts>=4 || tryCount>40) {
			//console.log("All web fonts loaded at try ", tryCount);
			removeWebFontNodes();
			allWebFontsLoaded();
			return;
		}
		else // try again later
			setTimeout(function(){
				waitForFonts(tryCount);
			}, 50);
	}

	//console.log(window.location.href, ": web font declared and loading...");
	setTimeout(function(){waitForFonts(0);}, 100);
}

//console.log("documentID set to: ", documentID);

requestPieStatus();

document.addEventListener("contextmenu", function(){
	chrome.extension.sendRequest({greeting: "pieContextMenuOpen", documentID: documentID});
}, false);

chrome.extension.onRequest.addListener(handleRequest);

