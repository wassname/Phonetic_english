This README file introduces each component of PIE's source code.

cmudict.0.7a.txt
==============================
This is the official CMU Pronouncing Dictionary obtained from
	http://www.speech.cs.cmu.edu/cgi-bin/pronounce .

cmudict.modified.txt
==============================
This is a modified version of cmudict.0.7a.txt. Modifications include:
	* All AH1 and AH2 are replaced with AHH1 and AHH2.
	* All ER1 and ER2 are replaced with ERR1 and ERR2.
	* Pronunciation errors in cmudict.0.7a.txt are fixed as we encounter them.

fragments.txt
==============================
This is a manually prepared list of spelling-to-pronunciation rules.

Rules that come earlier have higher priorities.

For each rule, the first column is the rule's spelling; the second column is the rule's pronunciation; the third column is the rule's PIE representation.

In a PIE representation, a ^ is a stress mark insertion point (where a stress mark should be inserted if a word's actual pronunciation data indicate a primary stress on that vowel); a * is a stress mark omission point (where a stress mark should always be omitted even if a word's actual pronunciation data indicate a primary stress on that vowel).

aligner.c
==============================
This is a C program that reads cmudict.modified.txt and fragments.txt, and uses a depth-first search to generate PIE pronunciation (International Edition, Full Mode) for each word in cmudict.modified.txt, outputting them to a file named pie_data.js.txt. pie_data.js.txt contains a JavaScript object named "pieData" which will be inserted at the beginning of "background.js" which is contained in "pie_international.zip" and "pie_american.zip" described below.

pie_international.zip
==============================
This zip file contains the unpacked version of Chrome extension "PIE (International)".

pie_american.zip
==============================
This zip file contains the unpacked version of Chrome extension "PIE (American)".

CherryPIE.zip
==============================
This zip file contains .woff font files for the Cherry PIE font used by PIE, along with related licensing information.

