function onGotIt()
{
	window.localStorage.setItem("showGuide", false);
	chrome.extension.getBackgroundPage().showGuide=false;
	window.close();
}

function onNextTime()
{
	window.localStorage.setItem("showGuide", true);
	chrome.extension.getBackgroundPage().showGuide=true;
	window.close();
}

document.getElementById("got-it").addEventListener("click", onGotIt);
document.getElementById("got-it-2").addEventListener("click", onGotIt);
document.getElementById("next-time").addEventListener("click", onNextTime);

