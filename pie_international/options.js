function onOKClick()
{
	var list, newlist, element;
	var bgpage=chrome.extension.getBackgroundPage();

	element=document.getElementById("font-seq");
	if (element.value.trim()=="") {
		window.localStorage.setItem("fontSeq", bgpage.defFontSeq);
		bgpage.fontSeq=bgpage.defFontSeq;
	}
	else {
		window.localStorage.setItem("fontSeq", element.value);
		bgpage.fontSeq=element.value;
	}

	var mode, modeName;
	if (document.getElementById("full-mode").checked==true) {
		mode=0;
		modeName="Full";
	}
	else if (document.getElementById("less-full-mode").checked==true) {
		mode=1;
		modeName="LessFull";
	}
	else if (document.getElementById("medium-mode").checked==true) {
		mode=2;
		modeName="Medium";
	}
	else if (document.getElementById("lite-mode").checked==true) {
		mode=3;
		modeName="Lite";
	}
	else {
		mode=4;
		modeName="ExtraLite";
	}
	window.localStorage.setItem("pieMode", modeName);
	bgpage.pieMode=mode;

	element=document.getElementById("weak-form");
	window.localStorage.setItem("showWeakForm", element.checked);
	bgpage.showWeak=element.checked;

	if (document.getElementById("default-fonts").checked==true)
		bgpage.useDefFonts=true;
	else
		bgpage.useDefFonts=false;
	window.localStorage.setItem("useDefFonts", bgpage.useDefFonts);

	element=document.getElementById("plus-sign");
	window.localStorage.setItem("showPlus", element.checked);
	bgpage.showPlus=element.checked;

	element=document.getElementById("dot-sign");
	window.localStorage.setItem("showDot", element.checked);
	bgpage.showDot=element.checked;

	element=document.getElementById("force-trans");
	window.localStorage.setItem("forceTrans", element.checked);
	bgpage.forceTrans=element.checked;

	element=document.getElementById("allowed");
	if (element.value.trim()=="")
		newlist=bgpage.defAllowList.slice(0);
	else {
		list=element.value.split("\n");
		newlist=[];
		for (var i=0; i<list.length; i++)
			if (list[i].trim()!="")
				newlist.push(list[i].trim());
	}
	window.localStorage.setItem("allowList", JSON.stringify(newlist));
	bgpage.allowList=newlist.slice(0);

	element=document.getElementById("disallowed");
	list=element.value.split("\n");
	newlist=[];
	for (var i=0; i<list.length; i++)
		if (list[i].trim()!="")
			newlist.push(list[i].trim());
	window.localStorage.setItem("disallowList", JSON.stringify(newlist));
	bgpage.disallowList=newlist.slice(0);

	bgpage.setTitle();
	bgpage.setupLiteMode();
	bgpage.setupShowDot();
	bgpage.setupFontSpecificDiacritics();

	chrome.windows.getAll({populate: true}, function(windows) {
		var i, j;
		for (i=0; i<windows.length; i++)
			for (j=0; j<windows[i].tabs.length; j++) {
				var actualFontSeq=bgpage.calcActualFont();

				var k, urlAllowed=false;
				for (k=0; k<bgpage.allowList.length; k++) {
					if (windows[i].tabs[j].url.indexOf(bgpage.allowList[k])>=0) {
						urlAllowed=true;
						break;
					}
				}
				if (urlAllowed==true)
					for (k=0; k<bgpage.disallowList.length; k++) {
						if (windows[i].tabs[j].url.indexOf(bgpage.disallowList[k])>=0) {
							urlAllowed=false;
							break;
						}
					}

				var options={};
				options.fontSeq=actualFontSeq;
				options.urlAllowed=urlAllowed;
				options.pieMode=bgpage.pieMode;
				chrome.tabs.sendRequest(windows[i].tabs[j].id, {greeting: "pieNewOptions", newOptions: options});
			}
		window.close();
	});
}

function onCancelClick()
{
	window.close();
}

function onUseDefFontsOrNot()
{
	document.getElementById("font-seq").disabled=document.getElementById("default-fonts").checked;
}

function onExplainIDigraphs(event)
{
	event.preventDefault();

	var node=document.getElementById("explain-idigraphs");
	if (node.style.display=="none")
		node.style.display="block";
	else
		node.style.display="none";
	
	return false;
}

function onInit()
{
	var bgpage=chrome.extension.getBackgroundPage();
	
	if (bgpage.bgInitialized!=true) {
		alert("PIE has not initialized yet. Please try again later.");
		window.close();
		return;
	}

	document.getElementById("font-seq").value=bgpage.fontSeq;

	if (bgpage.pieMode==0)
		document.getElementById("full-mode").checked=true;
	else if (bgpage.pieMode==1)
		document.getElementById("less-full-mode").checked=true;
	else if (bgpage.pieMode==2)
		document.getElementById("medium-mode").checked=true;
	else if (bgpage.pieMode==3)
		document.getElementById("lite-mode").checked=true;
	else
		document.getElementById("extra-lite-mode").checked=true;

	if (bgpage.useDefFonts==true)
		document.getElementById("default-fonts").checked=true;
	else
		document.getElementById("custom-fonts").checked=true;

	document.getElementById("plus-sign").checked=bgpage.showPlus;
	document.getElementById("dot-sign").checked=bgpage.showDot;

	if (bgpage.showWeak==true)
		document.getElementById("weak-form").checked=true;
	else
		document.getElementById("strong-form").checked=true;

	document.getElementById("force-trans").checked=bgpage.forceTrans;

	var list, element;

	list=bgpage.allowList;
	element=document.getElementById("allowed");
	element.value="";
	for (i=0; i<list.length; i++)
		element.value+=list[i]+"\n";

	list=bgpage.disallowList;
	element=document.getElementById("disallowed");
	element.value="";
	for (i=0; i<list.length; i++)
		element.value+=list[i]+"\n";

	document.getElementById("btnOK").addEventListener("click", onOKClick);
	document.getElementById("btnCancel").addEventListener("click", onCancelClick);
	document.getElementById("i-digraphs").addEventListener("click", onExplainIDigraphs);
	document.getElementById("default-fonts").addEventListener("click", onUseDefFontsOrNot);
	document.getElementById("custom-fonts").addEventListener("click", onUseDefFontsOrNot);

	onUseDefFontsOrNot();
}

document.addEventListener('DOMContentLoaded', onInit, false);

