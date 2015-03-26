#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* a_words[]={
	// original hand-entered
	"BASS",
	"CLOSE",
	"CONDUCT",
	"PRESENT",
	"PRESENTS",
	"READ",
	"RECORD",
	"RECORDS",
	"SEPARATE",
	"LEAD",
	"GRADUATE",
	"GRADUATES",
	"AFFILIATE",
	"AFFILIATES",
	"ASSOCIATE",
	"ASSOCIATES",
	"APPROPRIATE",
	"DELEGATE",
	"DELEGATES",
	"LIVE",
	"LIVES",
	"ESTIMATE",
	"ESTIMATES",
	"ADVOCATE",
	"ADVOCATES",
	"ROW",
	"ROWS",
	"ROWING",
	"ROWED",
	"INVALID",
	"USE",
	"USES",
//	"TRANSFER",
//	"TRANSFERS",
//	"PERFECT",
	"SUSPECT",
	"SUSPECTS",
	"WIND",
	"WOUND",
	"LEARNED",
	"DUPLICATE",
	"DUPLICATES",
	"TEAR",
	"TEARS",
	"SOW",
	"SOWS",
	"RESUME",
	"RESUMES",
	"AGGREGATE",
	"VIS",
	"CORRELATE",
	"CORRELATES",
	"SURROGATE",
	"SURROGATES",
	"DESERT",
	"DESERTS",
	"TOME",
	"DUMAS",
	"CONSOLE",
	"CONSOLES",
	"PREDICATE",
	"PREDICATES",
	"EJACULATE",
	"EJACULATES",
	"NOEL",
	"LYON",
	"LYONS",
	"JENSEN",
//	"PRAYER",
//	"PRAYERS",
//	"PRAYERFUL",
	"LOGOS",
	"DEMOS",
	"CONFEDERATE",
	"CONFEDERATES",

	// extracted from Moby Pronunciator II
	"ABSENT",
	"ABUSE",
	"ADDICT",
	"ADEPT",
	"ADVOCATE",
	"AFFILIATE",
//	"ALLOY",
//	"ALLY",
	"ALTERNATE",
	"ANIMATE",
	"APPROPRIATE",
	"APPROXIMATE",
	"ARTICULATE",
//	"ASSAY",
	"ASSOCIATE",
	"ATTRIBUTE",
	"CERTIFICATE",
	"CLEANLY",
	"CLOSE",
	"COAGULATE",
	"COMBINE",
	"COMMUNE",
//	"COMPLEMENT",
//	"COMPLIMENT",
//	"SUPPLEMENT",
//	"COMPOUND",
	"COMPRESS",
	"COMPRESSES",
	"CONDUCT",
//	"CONFLICT",
	"CONSCRIPT",
	"CONSERVE",
	"CONSORT",
	"CONSTRUCT",
	"CONSUMMATE",
	"CONTENT",
	"CONTENTS",
//	"CONTEST",
	"CONTRACT",
//	"CONTRAST",
	"CONVERSE",
	"CONVERT",
	"CONVICT",
//	"COORDINATE",
//	"COUNTERATTACK",
//	"COUNTERBALANCE",
//	"COUNTERCHARGE",
//	"COUNTERCHECK",
//	"COUNTERCLAIM",
//	"COUNTERLIGHT",
//	"COUNTERMARCH",
//	"COUNTERMARK",
//	"COUNTERMINE",
//	"COUNTERMOVE",
//	"COUNTERPLOT",
//	"COUNTERREPLY",
//	"COUNTERSTAIN",
//	"COUNTERSTAMP",
//	"COUNTERWORK",
	"DECREASE",
	"DEGENERATE",
	"DELEGATE",
	"DELIBERATE",
	"DESOLATE",
	"DIFFUSE",
	"DIGEST",
	"DISCARD",
//	"DISCHARGE",
//	"DISCOUNT",
//	"DISCOURSE",
	"DISUSE",
//	"DOCUMENT",
	"ELABORATE",
//	"ESCORT",
//	"ESSAY",
	"ESTIMATE",
//	"EXCERPT",
//	"EXCISE",
	"EXCUSE",
//	"EXTRACT",
//	"IMPORT",
//	"IMPORTS",
//	"EXPORT",
//	"EXPORTS",
//	"FREQUENT",
//	"JEAN",
//	"HERDER",
//	"MITRE",
//	"GALLANT",
	"GRADUATE",
	"HOUSE",
//	"IMPACT",
	"IMPLANT",
//	"IMPRINT",
//	"INCARNATE",
//	"INCLINE",
	"INCREASE",
//	"INITIATE",
	"INSULT",
	"INTERMEDIATE",
	"INTERMEDIATES",
	"INTERCEPT",
	"INTERCHANGE",
	"INTERCROSS",
//	"INTERCUT",
	"INTERDICT",
	"INTERFLOW",
	"INTERGRADE",
//	"INTERLINK",
//	"INTERLOCK",
	"INTERN",
	"INTOXICATE",
//	"INTRIGUE",
	"INVERT",
	"INVITE",
//	"INVOLUTE",
//	"LAMINATE",
	"LEAD",
	"MISCONDUCT",
	"MISESTIMATE",
//	"MISPRINT",
	"MISUSE",
	"MODERATE",
//	"MOUTH",
	"OBJECT",
//	"ORIENT",
//	"ORNAMENT",
//	"OUTCROP",
//	"OUTCROSS",
//	"OUTLAY",
//	"OUTRIDE",
//	"OUTSHOOT",
//	"OUTSPAN",
//	"OUTSPREAD",
//	"OVERBALANCE",
//	"OVERBID",
//	"OVERBURDEN",
//	"OVERCROP",
//	"OVERDOSE",
//	"OVERDRESS",
//	"OVERDRIVE",
//	"OVERHANG",
//	"OVERHAUL",
//	"OVERLAP",
//	"OVERLAY",
//	"OVERLOOK",
	"OVERMAN",
//	"OVERPRINT",
//	"OVERRIDE",
//	"OVERRUN",
//	"OVERSPILL",
//	"OVERSTITCH",
//	"OVERSTOCK",
//	"OVERSTRIKE",
//	"OVERSTUDY",
//	"OVERSUPPLY",
//	"OVERTURN",
	"OVERUSE",
//	"OVERWORK",
	"PERMIT",
	"PERVERT",
	"POLISH",
	"PREDESTINATE",
	"PRESENT",
	"PRODUCE",
	"PROGRESS",
	"PROGRESSES",
	"PROJECT",
	"PROPORTIONATE",
//	"PROTEST",
	"PURPORT",
	"QUADRUPLICATE",
	"REBEL",
//	"RECOIL",
	"RECORD",
//	"REDRESS",
//	"REFILL",
	"REFUND",
//	"REHASH",
	"REJECT",
//	"RELAPSE",
//	"REMATCH",
//	"REMOUNT",
//	"REPAINT",
//	"REPRINT",
//	"RERUN",
	"RESET",
//	"RESTRIKE",
//	"RESURVEY",
	"RETREAD",
	"REVERBERATE",
	"REWRITE",
//	"SATIATE",
//	"SATURATE",
//	"SEGMENT",
	"SEPARATE",
//	"SOJOURN",
//	"SUBCONTRACT",
	"SUBJECT",
//	"SUBLET",
	"SUBORDINATE",
//	"SUBSAMPLE",
//	"SUPERHEAT",
	"SUPINE",
	"SUSPECT",
	"SYNDICATE",
	"TABULATE",
//	"TORMENT",
//	"TRANSFER",
	"TRANSPLANT",
//	"TRANSPORT",
	"TRIANGULATE",
//	"UNDERCHARGE",
	"UNDERDRESS",
	"UNDERESTIMATE",
//	"UNDERLAY",
//	"UNDERLINE",
//	"UNDERSCORE",
//	"UNDERSTOCK",
//	"UNDERWEIGHT",
	"UNDULATE",
//	"UPRISE",
//	"UPSURGE",
//	"UPSWEEP",
//	"UPTHROW",
	"USE",
//	"WAREHOUSE",
	"WIND",
	"BOW",
	"BOWS",
//	"WAGNER",
//	"EXPLOIT",
//	"EXPLOITS",
	"SEWER",
	"SEWERS",
//	"TRANSFORM",
//	"TRANSFORMS",

	// -s entries derived from Moby Pronunciator II
	"ABUSES",
	"ADDICTS",
	"ADVOCATES",
	"AFFILIATES",
//	"ALLOYS",
//	"ALLIES",
	"ALTERNATES",
	"APPROPRIATES",
	"APPROXIMATES",
	"ARTICULATES",
	"ASSOCIATES",
	"ATTRIBUTES",
	"CERTIFICATES",
	"COMBINES",
	"COMMUNES",
//	"COMPLEMENTS",
//	"COMPLIMENTS",
//	"SUPPLEMENTS",
//	"COMPOUNDS",
	"CONDUCTS",
//	"CONFLICTS",
	"CONSCRIPTS",
	"CONSTRUCTS",
	"CONSUMMATES",
//	"CONTESTS",
	"CONTRACTS",
//	"CONTRASTS",
	"CONVERSES",
	"CONVERTS",
	"CONVICTS",
//	"COORDINATES",
//	"COUNTERATTACKS",
//	"COUNTERBALANCES",
//	"COUNTERCHARGES",
//	"COUNTERCLAIMS",
//	"COUNTERMOVES",
	"DECREASES",
	"DEGENERATES",
	"DELEGATES",
	"DIFFUSES",
	"DIGESTS",
	"DISCARDS",
//	"DISCHARGES",
//	"DISCOUNTS",
//	"DISCOURSES",
//	"DOCUMENTS",
//	"ESCORTS",
//	"ESSAYS",
	"ESTIMATES",
//	"EXCERPTS",
//	"EXCISES",
	"EXCUSES",
//	"EXTRACTS",
//	"FREQUENTS",
	"GRADUATES",
//	"HOUSES",
//	"IMPACTS",
	"IMPLANTS",
//	"IMPRINTS",
//	"INCLINES",
	"INCREASES",
	"INITIATES",
	"INSULTS",
	"INTERCEPTS",
	"INTERCHANGES",
	"INTERNS",
//	"INTRIGUES",
	"INVITES",
	"LAMINATES",
	"MODERATES",
//	"MISPRINTS",
	"MISUSES",
//	"MOUTHS",
	"OBJECTS",
//	"ORNAMENTS",
//	"OUTLAYS",
//	"OVERDOSES",
//	"OVERHANGS",
//	"OVERHAULS",
//	"OVERLAPS",
//	"OVERLAYS",
//	"OVERLOOKS",
//	"OVERRIDES",
//	"OVERRUNS",
//	"OVERTURNS",
	"OVERUSES",
//	"OVERWORKS",
	"PERMITS",
	"PERVERTS",
	"PRESENTS",
	"PROCEEDS",
	"PRODUCES",
	"PROJECTS",
//	"PROTESTS",
	"PURPORTS",
	"REBELS",
//	"RECOILS",
	"RECORDS",
//	"REFILLS",
	"REFUNDS",
	"REJECTS",
//	"RELAPSES",
//	"REPRINTS",
//	"RERUNS",
	"RESETS",
	"RETREADS",
	"REVERBERATES",
	"REWRITES",
//	"SEGMENTS",
//	"SUBCONTRACTS",
	"SUBJECTS",
	"SUBORDINATES",
	"SUSPECTS",
	"SYNDICATES",
//	"TORMENTS",
//	"TRANSFERS",
	"TRANSPLANTS",
//	"TRANSPORTS",
	"UNDERESTIMATES",
//	"UNDERLINES",
//	"UNDERSCORES",
	"UNDULATES",
	"USES",
//	"WAREHOUSES",
	"WINDS"
};

char* strrstr(char* mainstr, char* substr)
{
	char* result=NULL;
	char* start=mainstr;
	char* p;
	while (1) {
		p=strstr(start, substr);
		if (p==NULL)
			return result;
		result=p;
		start=p+1;
	}
}

const char tab_char = 9;
int fragcount=0;

typedef struct {
	char* spelling;
	char* upron;
	char* pie;
	int spellinglen;
	int upronlen;
} t_frag, *p_frag;

t_frag frags[10000];
char baseform[100];
char wordpron[1000];
char wordupron[1000];
int baseformlen;
int wordupronlen;
int fragplan[100];
int fragplanlen;
char wordpie[1000];
int pvn; // pronunciation variant number

char prevword[100];
char goodpie[1000];
int multipie;
int begins_with_vowel;
int is_heteronym;

FILE* cmuf;
FILE* pief;

void readfrags()
{
	FILE* fragf=fopen("fragments.txt", "r");
	char bufline[1000];
	char *p, *q, *r, *s;
	char spelling[1000];
	char upron[1000]; // pronunciation without stress info
	char pie[1000];
	int i;

	while (fgets(bufline, 1000, fragf)) {
		i=strlen(bufline);

		// remove trailing newline
		if (bufline[i-1]=='\n')
			bufline[i-1]=0;

		// ignore comments
		if (strstr(bufline, ";;;")==bufline)
			continue;

		// find the two |'s on each line
		p=strstr(bufline, "|");
		if (!p)
			continue;
		q=strstr(p+1, "|");
		if (!q)
			continue;

		// extract spelling
		r=p-1;
		while ((*r==' ') || (*r==tab_char))
			r--;

		memcpy(spelling, bufline, r-bufline+1);
		spelling[r-bufline+1]=0;

		// extract pronunciation
		r=p+1;
		while ((*r==' ') || (*r==tab_char))
			r++;

		s=q-1;
		while ((*s==' ') || (*s==tab_char))
			s--;

		if (r>s)
			strcpy(upron, "");
		else {
			memcpy(upron, r, s-r+1);
			upron[s-r+1]=' ';
			upron[s-r+2]=0;
		}

		// extract pie
		r=q+1;
		while ((*r==' ') || (*r==tab_char))
			r++;

		strcpy(pie, r);

		frags[fragcount].spelling=(char*)malloc(strlen(spelling)+1);
		strcpy(frags[fragcount].spelling, spelling);
		frags[fragcount].spellinglen=strlen(spelling);

		frags[fragcount].upron=(char*)malloc(strlen(upron)+1);
		strcpy(frags[fragcount].upron, upron);
		frags[fragcount].upronlen=strlen(upron);

		frags[fragcount].pie=(char*)malloc(strlen(pie)+1);
		strcpy(frags[fragcount].pie, pie);

		// printf("SPELLING: %s....UPRON: %s....UPRONLEN: %i....PIE: %s....\n", spelling, upron, upronlen, pie);
		fragcount++;
	}

	fclose(fragf);
}

void freefrags()
{
	int i;
	for (i=0; i<fragcount; i++) {
		free(frags[i].spelling);
		free(frags[i].upron);
		free(frags[i].pie);
	}
}

int search(int spelling_filled, int upron_filled, int frags_filled)
{
	int i;

	if (spelling_filled==baseformlen) { // spelling filled up
		if (upron_filled==wordupronlen) { // upron also filled up
			fragplanlen=frags_filled;
			return 1; // successful
		}
		return 0;
	}

	for (i=0; i<fragcount; i++) {
		if (spelling_filled+frags[i].spellinglen>baseformlen) // fragment candidate causes spelling overflow
			continue;

		if (upron_filled+frags[i].upronlen>wordupronlen) // fragment candidate causes upron overflow
			continue;

		if ((memcmp(frags[i].spelling, baseform+spelling_filled, frags[i].spellinglen)==0) &&
		    (memcmp(frags[i].upron, wordupron+upron_filled, frags[i].upronlen)==0)) {
				if (search(spelling_filled+frags[i].spellinglen, upron_filled+frags[i].upronlen, frags_filled+1)) {
					fragplan[frags_filled]=i;
					return 1;
				}
			}
	}

	return 0;
}

void remove_defaults(char* pie)
{
	char pie0[1000];
	int i, j, left_v, right_v;
	char* p;

	strcpy(pie0, pie);

	for (i=0; i<strlen(pie0); i++)
		if (strncmp(pie0+i, "A&#769;^", 8)==0 ||
		    strncmp(pie0+i, "E&#769;^", 8)==0 ||
		    strncmp(pie0+i, "I&#769;^", 8)==0 ||
		    strncmp(pie0+i, "O&#769;^", 8)==0 ||
		    strncmp(pie0+i, "U&#769;^", 8)==0) { // got A/E/I/O/U with default short vowel mark

				// the nearest left-side letter is a vowel letter or a letter with vowel diacritic?
				left_v=0;
				p=pie0+i-1;
				while (p>=pie0) {
					if (*p>='A' && *p<='Z') {
						if (*p=='A' || *p=='E' || *p=='I' || *p=='O')
							left_v=1;
						else if (*p=='U') {
							if (strncmp(p+1, "&#840;", 6)!=0) // not with a "||" below
								left_v=1;
						}
						else if (*p=='Y' || *p=='W') {
							if (strncmp(p+1, "&#772;", 6)==0 // "-"
							    || strncmp(p+1, "&#776;", 6)==0 // ".."
							    || strncmp(p+1, "&#768;", 6)==0 // "\"
							    || strncmp(p+1, "&#769;", 6)==0 // "/"
							    || strncmp(p+1, "&#774;", 6)==0 // "U"
							    || strncmp(p+1, "&#781;", 6)==0) // "|"
								left_v=1;
						}
						break;
					}
					else if (*p=='-' || *p=='_' || *p=='\'')
						break;
					p--;
				}

				// the nearest right-side letter is a vowel letter or a letter with vowel diacritic?
				right_v=0;
				p=pie0+i+1;
				while (*p) {
					if (*p>='A' && *p<='Z') {
						if (*p=='A' || *p=='E' || *p=='I' || *p=='O')
							right_v=1;
						else if (*p=='U') {
							if (strncmp(p+1, "&#840;", 6)!=0) // not with a "||" below
								right_v=1;
						}
						else if (*p=='Y' || *p=='W' || *p=='R') {
							// and it has a vowel mark?
							if (strncmp(p+1, "&#772;", 6)==0 // "-"
							    || strncmp(p+1, "&#776;", 6)==0 // ".."
							    || strncmp(p+1, "&#768;", 6)==0 // "\"
							    || strncmp(p+1, "&#769;", 6)==0 // "/"
							    || strncmp(p+1, "&#774;", 6)==0 // "U"
							    || strncmp(p+1, "&#781;", 6)==0) // "|"
								right_v=1;
						}
						break;
					}
					else if (*p=='-' || *p=='_' || *p=='\'')
						break;
					p++;
				}

				// if neither side's nearest letter is a vowel letter (A/E/I/O/U) or letter with
				// vowel diacritic, we can remove the current vowel letter's default short vowel
				// mark.
				if (left_v==0 && right_v==0)
					memcpy(pie0+i+1, "      ", 6);
			}

	// reconstruct pie by copying pie0 but removing spaces
	j=0;
	for (i=0; i<strlen(pie0); i++)
		if (pie0[i]!=' ') {
			pie[j]=pie0[i];
			j++;
		}
	pie[j]=0;
}

void remove_silences(char* pie)
{
	char pie0[1000];
	int refreshed, i, j, left_v, right_v;
	char* p;

	strcpy(pie0, pie);

	do {
		refreshed=0;
		for (i=0; i<strlen(pie0); i++)
			if (strncmp(pie0+i, "A&#775;", 7)==0 ||
			    strncmp(pie0+i, "E&#775;", 7)==0 ||
			    strncmp(pie0+i, "I&#821;", 7)==0 ||
			    strncmp(pie0+i, "O&#775;", 7)==0 ||
			    strncmp(pie0+i, "U&#775;", 7)==0 ||
			    strncmp(pie0+i, "U&#821;", 7)==0) { // got a silent A/E/I/O/U
					// the nearest left-side letter is a vowel letter?
					left_v=0;
					p=pie0+i-1;
					while (p>=pie0) {
						if (*p>='A' && *p<='Z') {
							if (*p=='A' || *p=='E' || *p=='I' || *p=='O' || *p=='U') {
								// and it is not silenced?
								if (!(strncmp(p+1, "&#775;", 6)==0 || strncmp(p+1, "&#821;", 6)==0))
									// and it's not with a || below
									if (strncmp(p+1, "&#840;", 6)!=0)
									left_v=1;
							}
							else if (*p=='Y' || *p=='W') {
								// and it has a vowel mark?
								if (strncmp(p+1, "&#772;", 6)==0 // "-"
								    || strncmp(p+1, "&#776;", 6)==0 // ".."
								    || strncmp(p+1, "&#768;", 6)==0 // "\"
								    || strncmp(p+1, "&#769;", 6)==0 // "/"
								    || strncmp(p+1, "&#774;", 6)==0 // "U"
								    || strncmp(p+1, "&#781;", 6)==0) // "|"
									left_v=1;
							}
							break;
						}
						else if (*p=='-' || *p=='_' || *p=='\'')
							break;
						p--;
					}

					// the nearest right-side letter is a vowel letter?
					right_v=0;
					p=pie0+i+1;
					while (*p) {
						if (*p>='A' && *p<='Z') {
							if (*p=='A' || *p=='E' || *p=='I' || *p=='O' || *p=='U') {
								// and it is not silenced?
								if (!(strncmp(p+1, "&#775;", 6)==0 || strncmp(p+1, "&#821;", 6)==0))
									// and it's not with a || below
									if (strncmp(p+1, "&#840;", 6)!=0)
									right_v=1;
							}
							else if (*p=='Y' || *p=='W') {
								// and it has a vowel mark?
								if (strncmp(p+1, "&#772;", 6)==0 // "-"
								    || strncmp(p+1, "&#776;", 6)==0 // ".."
								    || strncmp(p+1, "&#768;", 6)==0 // "\"
								    || strncmp(p+1, "&#769;", 6)==0 // "/"
								    || strncmp(p+1, "&#774;", 6)==0 // "U"
								    || strncmp(p+1, "&#781;", 6)==0) // "|"
									right_v=1;
							}
							else if (*p=='R') {
								// and it has a vowel mark above?
								if (strncmp(p+1, "&#768;", 6)==0 // "\"
								    || strncmp(p+1, "&#776;", 6)==0) // ".."
									right_v=1;
							}
							break;
						}
						else if (*p=='-' || *p=='_' || *p=='\'')
							break;
						p++;
					}

					// if either side's nearest letter is an unsilenced vowel letter,
					// we can remove the current vowel letter's silence mark
					if (left_v || right_v) {
						refreshed=1;
						memcpy(pie0+i+1, "      ", 6);
					}
				}
	} while (refreshed);

	// reconstruct pie by copying pie0 but removing spaces
	j=0;
	for (i=0; i<strlen(pie0); i++)
		if (pie0[i]!=' ') {
			pie[j]=pie0[i];
			j++;
		}
	pie[j]=0;
}

void remove_redundant_silent_consonant_letters(char* pie)
{
	char pie0[1000];
	int refreshed, i, j;
	
	strcpy(pie0, pie);

	do {
		refreshed=0;
		for (i=0; i<strlen(pie0); i++) {
			if (pie0[i]!='A' && pie0[i]!='E' && pie0[i]!='I' && pie0[i]!='O' && pie0[i]!='U' &&
			(strncmp(pie0+i+1, "&#775;", 6)==0 || strncmp(pie0+i+1, "&#821;", 6)==0) &&
			pie0[i]==pie0[i-1]) {
				refreshed=1;
				memcpy(pie0+i+1, "      ", 6);
			}
		}
	} while (refreshed);

	// reconstruct pie by copying pie0 but removing spaces
	j=0;
	for (i=0; i<strlen(pie0); i++)
		if (pie0[i]!=' ') {
			pie[j]=pie0[i];
			j++;
		}
	pie[j]=0;
}

void html_to_js_encoding()
{
	char jsstr[1000];
	char *p_html, *p_js;

	p_html=wordpie;
	p_js=jsstr;

	while (*p_html) {
		if (strncmp(p_html, "&#", 2)==0) {
			if (strncmp(p_html, "&#768;", 6)==0)
				strcpy(p_js, "\\u0300");
			else if (strncmp(p_html, "&#770;", 6)==0)
				strcpy(p_js, "\\u0302");
			else if (strncmp(p_html, "&#769;", 6)==0)
				strcpy(p_js, "\\u0301");
			else if (strncmp(p_html, "&#772;", 6)==0)
				strcpy(p_js, "\\u0304");
			else if (strncmp(p_html, "&#774;", 6)==0)
				strcpy(p_js, "\\u0306");
			else if (strncmp(p_html, "&#775;", 6)==0)
				strcpy(p_js, "\\u0307");
			else if (strncmp(p_html, "&#776;", 6)==0)
				strcpy(p_js, "\\u0308");
			else if (strncmp(p_html, "&#778;", 6)==0)
				strcpy(p_js, "\\u030a");
			else if (strncmp(p_html, "&#779;", 6)==0)
				strcpy(p_js, "\\u030b");
			else if (strncmp(p_html, "&#781;", 6)==0)
				strcpy(p_js, "\\u030d");
			else if (strncmp(p_html, "&#782;", 6)==0)
				strcpy(p_js, "\\u030e");
			else if (strncmp(p_html, "&#783;", 6)==0)
				strcpy(p_js, "\\u030f");
			else if (strncmp(p_html, "&#803;", 6)==0)
				strcpy(p_js, "\\u0323");
			else if (strncmp(p_html, "&#804;", 6)==0)
				strcpy(p_js, "\\u0324");
			else if (strncmp(p_html, "&#807;", 6)==0)
				strcpy(p_js, "\\u0327");
			else if (strncmp(p_html, "&#808;", 6)==0)
				strcpy(p_js, "\\u0328");
			else if (strncmp(p_html, "&#809;", 6)==0)
				strcpy(p_js, "\\u0329");
			else if (strncmp(p_html, "&#817;", 6)==0)
				strcpy(p_js, "\\u0331");
			else if (strncmp(p_html, "&#821;", 6)==0)
				strcpy(p_js, "\\u0335");
			else if (strncmp(p_html, "&#840;", 6)==0)
				strcpy(p_js, "\\u0348");
			else if (strncmp(p_html, "&#849;", 6)==0)
				strcpy(p_js, "\\u0351");
			else if (strncmp(p_html, "&#855;", 6)==0)
				strcpy(p_js, "\\u0357");
			else if (strncmp(p_html, "&#183;", 6)==0)
				strcpy(p_js, "\\u2e31"); // using this character as an internal code; final web page output will still use &#183

			p_html+=6;
			p_js+=6;
		}
		else {
			*p_js=*p_html;
			p_html++;
			p_js++;
		}
	}

	*p_js=0;
	strcpy(wordpie, jsstr);
}

void check_if_heteronym()
{
	int a_words_size=sizeof(a_words)/sizeof(char*);
	int i;
	for (i=0; i<a_words_size; i++)
		if (strcmp(baseform, a_words[i])==0) {
			is_heteronym=1;
			break;
		}
}

void simplify_stresses(char* prepie, char* vowel_arr, int n_vowels, int start_vowel_pos, int end_vowel_pos)
{
	int i;
	
	if (start_vowel_pos<0 || start_vowel_pos>=strlen(prepie) ||
	    end_vowel_pos<0 || end_vowel_pos>=strlen(prepie) ||
	    end_vowel_pos<start_vowel_pos)
		return;

	if (start_vowel_pos==end_vowel_pos) { // only one vowel in this range
		prepie[start_vowel_pos]='*';
		return;
	}

	// get start vowel number and end vowel number
	int start_vowel_number, end_vowel_number, cur_vowel_number=-1;
	for (i=0; i<strlen(prepie); i++)
		if (prepie[i]=='^' || prepie[i]=='*') {
			cur_vowel_number++;
			if (i==start_vowel_pos)
				start_vowel_number=cur_vowel_number;
			else if (i==end_vowel_pos)
				end_vowel_number=cur_vowel_number;
		}
	
	// remove all primary stresses except the first one
	int first_primary=-1;
	for (i=start_vowel_number; i<=end_vowel_number; i++)
		if (vowel_arr[i]=='1') {
			if (first_primary>=0)
				vowel_arr[i]='2';
			else
				first_primary=i;
		}

	if (first_primary==-1 && end_vowel_number-start_vowel_number>=1) { // more than one vowels but no primary stress
		// set the first secondary stress to primary stress
		for (i=start_vowel_number; i<=end_vowel_number; i++)
			if (vowel_arr[i]=='2') {
				vowel_arr[i]='1';
				break;
			}
	}
	
	// if there are at least 3 syllables before the primary-stress syllable,
	// elevate all secondary stresses among them to "primary" stresses.
	if (first_primary-start_vowel_number>=3) {
		for (i=start_vowel_number; i<first_primary; i++)
			if (vowel_arr[i]=='2')
				vowel_arr[i]='1';
	}
	else if (first_primary-start_vowel_number==2 && vowel_arr[start_vowel_number]=='0' && vowel_arr[start_vowel_number+1]=='2') {
		// if there are two syllables before the primary-stress syllable, and they follow the '0-2' stress pattern
		vowel_arr[start_vowel_number+1]='1'; // elevate the second syllable's stress to "primary"
	}
}

int not_before_vowel(char* wordpie, int pos)
{
	int nbv=1, i=pos-1;
	char* p;
	while (i>=0) {
		p=wordpie+i;
		if (*p>='A' && *p<='Z') {
			if (*p=='A' || *p=='E' || *p=='I' || *p=='O')
				nbv=0;
			else if (*p=='U') {
				if (strncmp(p+1, "&#840;", 6)!=0) // not with a "||" below
					nbv=0;
			}
			else if (*p=='Y' || *p=='W') {
				if (strncmp(p+1, "&#772;", 6)==0 // "-"
				    || strncmp(p+1, "&#776;", 6)==0 // ".."
				    || strncmp(p+1, "&#768;", 6)==0 // "\"
				    || strncmp(p+1, "&#769;", 6)==0 // "/"
				    || strncmp(p+1, "&#774;", 6)==0 // "U"
				    || strncmp(p+1, "&#781;", 6)==0) // "|"
					nbv=0;
			}
			break;
		}
		else if (*p=='-' || *p=='_')
			break;
		i--;
	}

	return nbv;
}

int get_emp_pos_helper(char* wordpie, int range_start, int range_end)
{
	if (range_start>range_end)
		return -1;

	if (range_end-2>=0 && strncmp(wordpie+range_end-2, "E L", 3)==0 && not_before_vowel(wordpie, range_end-2))
		return range_end-2;
	else if (range_end-9>=0 && strncmp(wordpie+range_end-9, "E LS&#809;", 10)==0 && not_before_vowel(wordpie, range_end-9))
		return range_end-9;
	else if (range_end-10>=0 && strncmp(wordpie+range_end-10, "E LE&#775;D", 11)==0 && not_before_vowel(wordpie, range_end-10))
		return range_end-10;
	else if (range_end-18>=0 && strncmp(wordpie+range_end-18, "E LI N&#809;G&#821;", 19)==0 && not_before_vowel(wordpie, range_end-18))
		return range_end-18;
	else if (range_end-2>=0 && strncmp(wordpie+range_end-2, "A L", 3)==0 && not_before_vowel(wordpie, range_end-2))
		return range_end-2;
	else if (range_end-9>=0 && strncmp(wordpie+range_end-9, "A LS&#809;", 10)==0 && not_before_vowel(wordpie, range_end-9))
		return range_end-9;
	else if (range_end-1>=0 && strncmp(wordpie+range_end-1, "E ", 2)==0 && not_before_vowel(wordpie, range_end-1))
		return range_end-1;
	else if (range_end-8>=0 && strncmp(wordpie+range_end-8, "E S&#809;", 9)==0 && not_before_vowel(wordpie, range_end-8))
		return range_end-8;
	else if (range_end-2>=0 && strncmp(wordpie+range_end-2, "E R", 3)==0 && not_before_vowel(wordpie, range_end-2))
		return range_end-2;
	else if (range_end-2>=0 && strncmp(wordpie+range_end-2, "E S", 3)==0 && not_before_vowel(wordpie, range_end-2))
		return range_end-2;
	else if (range_end-4>=0 && strncmp(wordpie+range_end-4, "NE SS", 5)==0)
		return range_end-3;
	else if (range_end-8>=0 && strncmp(wordpie+range_end-8, "O&#776; R", 9)==0)
		return range_end-2;
	else if (range_end-15>=0 && strncmp(wordpie+range_end-15, "O&#776; RS&#809;", 16)==0)
		return range_end-9;
	
	return -1;
}

int get_emp_pos(char* prepie, char* wordpie, int range_start, int range_end)
{
	int i, j;

	j=0;
	for (i=range_start; i<=range_end; i++)
		if (prepie[i]=='^' || prepie[i]=='*')
			j++;
	if (j<=1)
		return -1;

	if (range_end-7>=0 && strncmp(wordpie+range_end-7, "'S&#809;", 8)==0)
		return get_emp_pos_helper(wordpie, range_start, range_end-8);
	else if (range_end-1>=0 && strncmp(wordpie+range_end-1, "'S", 2)==0)
		return get_emp_pos_helper(wordpie, range_start, range_end-2);
	else if (range_end>=0 && strncmp(wordpie+range_end, "'", 1)==0)
		return get_emp_pos_helper(wordpie, range_start, range_end-1);
	else
		return get_emp_pos_helper(wordpie, range_start, range_end);
}

void assemble_pie()
{
	char prepie[1000];
	int i, j, k, vowels, ins_points;
	char vowel[100];

	strcpy(prepie, "");
	for (i=0; i<fragplanlen; i++)
		strcat(prepie, frags[fragplan[i]].pie);

	// remove unnecessary default short vowel marks for A, E, I, O, U
	remove_defaults(prepie);

	// remove unnecessary silence marks for A, E, I, O, U
	remove_silences(prepie);

	remove_redundant_silent_consonant_letters(prepie);

	// count vowels in wordpron
	int nstress1=0;
	vowels=0;
	for (i=0; i<strlen(wordpron); i++)
		if (wordpron[i]>='0' && wordpron[i]<='2') {
			vowel[vowels]=wordpron[i];
			vowels++;
			if (wordpron[i]=='1')
				nstress1++;
		}

	// count stress insertion points in prepie
	ins_points=0;
	for (i=0; i<strlen(prepie); i++)
		if (prepie[i]=='^' || prepie[i]=='*')
			ins_points++;

	// does vowels and ins_points match?
	if (vowels != ins_points) {
		printf("Vowels in wordpron and insertion points in prepie don't match!\n");
		printf("wordpron: %s\n", wordpron);
		printf("prepie: %s\n", prepie);
		printf("\n");
	}

	int start_vowel_pos=-1, cur_vowel_pos=-1;
	for (i=0; i<strlen(prepie); i++)
		if (prepie[i]=='^' || prepie[i]=='*') {
			cur_vowel_pos=i;
			if (start_vowel_pos==-1)
				start_vowel_pos=cur_vowel_pos;
		}
		else if (prepie[i]=='-' || prepie[i]=='_') {
			simplify_stresses(prepie, vowel, vowels, start_vowel_pos, cur_vowel_pos);
			start_vowel_pos=-1;
		}
	simplify_stresses(prepie, vowel, vowels, start_vowel_pos, cur_vowel_pos);
	
	// add stress points
	k=0;
	for (i=0; i<strlen(prepie); i++) {
		if (prepie[i]!='^' && prepie[i]!='*')
			wordpie[i]=prepie[i];
		else if (prepie[i]=='*') {
			wordpie[i]=' ';
			k++;
		}
		else {
			if (vowel[k]=='1')
				wordpie[i]='^';
			else
				wordpie[i]=' ';
			k++;
		}
	}
	wordpie[i]=0;

	// emphasize certain suffixes
	int range_start=0, range_end;
	int emp_pos[100], emps=0;
	for (i=0; i<strlen(wordpie); i++)
		if (wordpie[i]=='-' || wordpie[i]=='_') {
			range_end=i-1;
			if (range_start<=range_end) {
				j=get_emp_pos(prepie, wordpie, range_start, range_end);
				if (j>=0) {
					emp_pos[emps]=j;
					emps++;
				}
			}
			range_start=i+1;
		}
	range_end=strlen(wordpie)-1;
	if (range_start<=range_end) {
		j=get_emp_pos(prepie, wordpie, range_start, range_end);
		if (j>=0) {
			emp_pos[emps]=j;
			emps++;
		}
	}

	if (emps>0) {
		strcpy(prepie, wordpie);
		j=0; k=0;
		for (i=0; i<strlen(prepie); i++) {
			wordpie[k]=prepie[i]; k++;
			if (j<emps && i==emp_pos[j]+j) {
				wordpie[k]='*'; k++; j++; // '*' now means an acute mark which will be realized later
			}
		}
		wordpie[k]=0;
	}

	// finish adding stress points
	strcpy(prepie, wordpie);
	j=0;
	for (i=0; i<strlen(prepie); i++)
		if (prepie[i]==' ')
			;
		else if (prepie[i]=='^') {
			wordpie[j]=0;
			strcat(wordpie, "&#803;");
			j=strlen(wordpie);
		}
		else if (prepie[i]=='*') {
			wordpie[j]=0;
			strcat(wordpie, "&#769;");
			j=strlen(wordpie);
		}
		else {
			wordpie[j]=prepie[i];
			j++;
		}
	wordpie[j]=0;

	html_to_js_encoding();
	check_if_heteronym();
	if (is_heteronym==0) {
		if (begins_with_vowel==0)
			;
		else
			strcat(wordpie, "{"); // not heteronym and begins with vowel
	}
	else {
		if (begins_with_vowel==0)
			strcat(wordpie, "|"); // is heteronym and begins with consonant
		else
			strcat(wordpie, "}"); // is heteronym and begins with vowel
	}
}

void print_pief_header()
{
	fprintf(pief, "// The following \"pieData\" is derived from the CMU Pronouncing Dictionary and Moby Pronunciator II. Moby\n");
	fprintf(pief, "// Pronunciator II also provides words whose meaning varies with pronunciation (heteronyms). PIE can\n");
	fprintf(pief, "// optionally show a small plus sign after such words.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// CMU Pronouncing Dictionary is Copyright (C) 1993-2008, Carnegie Mellon University. All rights reserved.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// CMU Pronouncing Dictionary can be obtained from http://www.speech.cs.cmu.edu/cgi-bin/cmudict.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// The license for CMU Pronouncing Dictionary is as follows:\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// ========================================================================\n");
	fprintf(pief, "// Copyright (C) 1993-2008 Carnegie Mellon University. All rights reserved.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// Redistribution and use in source and binary forms, with or without\n");
	fprintf(pief, "// modification, are permitted provided that the following conditions\n");
	fprintf(pief, "// are met:\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// 1. Redistributions of source code must retain the above copyright\n");
	fprintf(pief, "//    notice, this list of conditions and the following disclaimer.\n");
	fprintf(pief, "//    The contents of this file are deemed to be source code.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// 2. Redistributions in binary form must reproduce the above copyright\n");
	fprintf(pief, "//    notice, this list of conditions and the following disclaimer in\n");
	fprintf(pief, "//    the documentation and/or other materials provided with the\n");
	fprintf(pief, "//    distribution.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// This work was supported in part by funding from the Defense Advanced\n");
	fprintf(pief, "// Research Projects Agency, the Office of Naval Research and the National\n");
	fprintf(pief, "// Science Foundation of the United States of America, and by member\n");
	fprintf(pief, "// companies of the Carnegie Mellon Sphinx Speech Consortium. We acknowledge\n");
	fprintf(pief, "// the contributions of many volunteers to the expansion and improvement of\n");
	fprintf(pief, "// this dictionary.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY ``AS IS'' AND\n");
	fprintf(pief, "// ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,\n");
	fprintf(pief, "// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\n");
	fprintf(pief, "// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY\n");
	fprintf(pief, "// NOR ITS EMPLOYEES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,\n");
	fprintf(pief, "// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT\n");
	fprintf(pief, "// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\n");
	fprintf(pief, "// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\n");
	fprintf(pief, "// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n");
	fprintf(pief, "// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n");
	fprintf(pief, "// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// ========================================================================\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// Moby Pronunciator II is a public domain pronouncing dictionary created by Grady Ward.\n");
	fprintf(pief, "// \n");
	fprintf(pief, "// Moby Pronunciator II can be obtained from http://www.gutenberg.org/ebooks/3205.\n");
	fprintf(pief, "\n");

	fprintf(pief, "var pieData={\n");
}

int if_begins_with_vowel()
{
	if (
	    (strstr(wordupron, "AA")==wordupron) ||
	    (strstr(wordupron, "AE")==wordupron) ||
	    (strstr(wordupron, "AH")==wordupron) ||
	    (strstr(wordupron, "AO")==wordupron) ||
	    (strstr(wordupron, "AW")==wordupron) ||
	    (strstr(wordupron, "AY")==wordupron) ||
	    (strstr(wordupron, "EH")==wordupron) ||
	    (strstr(wordupron, "ER")==wordupron) ||
	    (strstr(wordupron, "EY")==wordupron) ||
	    (strstr(wordupron, "IH")==wordupron) ||
	    (strstr(wordupron, "IY")==wordupron) ||
	    (strstr(wordupron, "OW")==wordupron) ||
	    (strstr(wordupron, "OY")==wordupron) ||
	    (strstr(wordupron, "UH")==wordupron) ||
	    (strstr(wordupron, "UW")==wordupron) ||
	    (strstr(wordupron, "AHH")==wordupron) ||
	    (strstr(wordupron, "ERR")==wordupron))
		return 1;
	else
		return 0;
}

int main()
{
	// read fragments.txt to frags[]
	readfrags();

	// read cmudict do the alignment, output to pie.html
	cmuf=fopen("cmudict.modified.txt", "r");
	pief=fopen("pie_data.js.txt", "w");

	printf("Unresolved words:\n\n");

	print_pief_header();

	int i, j, k;
	char* p, *q;
	char workbuf[1000];
	int nwords=0, nsucc=0;
	char cmuline[1000];

	strcpy(prevword, "");
	multipie=0;

	while (fgets(cmuline, 1000, cmuf)) {
		i=strlen(cmuline);

		// remove trailing newline
		if (cmuline[i-1]=='\n')
			cmuline[i-1]=0;

		// ignore comments
		if (strstr(cmuline, ";;;")==cmuline)
			continue;

		// get word form
		if (sscanf(cmuline, "%s", baseform)==EOF)
			break;

		begins_with_vowel=0;
		is_heteronym=0;
		
		j=strlen(baseform);

		// get pronunciation variant number
		p=strstr(baseform,"(");
		if (p) {
			q=strstr(baseform,")");
			memcpy(workbuf, p+1, q-p-1);
			workbuf[q-p-1]=0;
			pvn=atoi(workbuf);
			*p=0;
		}
		else
			pvn=0;
		baseformlen=strlen(baseform);

		if (
			(strcmp(baseform, "CLOSE-UP")!=0)
		&& (
			(strstr(baseform, "-UP")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-DOWN")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-AWAY")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-ON")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-OFF")==baseform+strlen(baseform)-4) ||
			(strstr(baseform, "-UNDER")==baseform+strlen(baseform)-6) ||
			(strstr(baseform, "-IN")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-OUT")==baseform+strlen(baseform)-4) ||
			(strstr(baseform, "-AFTER")==baseform+strlen(baseform)-6) ||
			(strstr(baseform, "-BEFORE")==baseform+strlen(baseform)-7) ||
			(strstr(baseform, "-TO")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-FROM")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-BACK")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-FORWARD")==baseform+strlen(baseform)-8) ||
			(strstr(baseform, "-THROUGH")==baseform+strlen(baseform)-8) ||
			(strstr(baseform, "-INSIDE")==baseform+strlen(baseform)-7) ||
			(strstr(baseform, "-OUTSIDE")==baseform+strlen(baseform)-8) ||
			(strstr(baseform, "-AROUND")==baseform+strlen(baseform)-7) ||
			(strstr(baseform, "-ROUND")==baseform+strlen(baseform)-6) ||
			(strstr(baseform, "-OF")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-AT")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-INTO")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-ONTO")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-ALONG")==baseform+strlen(baseform)-6) ||
			(strstr(baseform, "-ABOVE")==baseform+strlen(baseform)-6) ||
			(strstr(baseform, "-OVER")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-WITH")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-BY")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-THAN")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-AS")==baseform+strlen(baseform)-3) ||
			(strstr(baseform, "-AGAINST")==baseform+strlen(baseform)-8) ||
			(strstr(baseform, "-ABOUT")==baseform+strlen(baseform)-6) ||
			(strstr(baseform, "-NEAR")==baseform+strlen(baseform)-5) ||
			(strstr(baseform, "-FOR")==baseform+strlen(baseform)-4) ||
			(strstr(baseform, "-TOGETHER")==baseform+strlen(baseform)-9) ||
			(strstr(baseform, "-IT")==baseform+strlen(baseform)-3) ||

		   (strstr(baseform, "UP-")==baseform) ||
		   	(strstr(baseform, "DOWN-")==baseform) ||
			(strstr(baseform, "AWAY-")==baseform) ||
		   (strstr(baseform, "ACROSS-")==baseform) ||
			(strstr(baseform, "ON-")==baseform) ||
			(strstr(baseform, "OFF-")==baseform) ||
			(strstr(baseform, "UNDER-")==baseform) ||
			(strstr(baseform, "IN-")==baseform) ||
			(strstr(baseform, "OUT-")==baseform) ||
			(strstr(baseform, "AFTER-")==baseform) ||
			(strstr(baseform, "BEFORE-")==baseform) ||
			(strstr(baseform, "TO-")==baseform) ||
			(strstr(baseform, "FROM-")==baseform) ||
			(strstr(baseform, "BACK-")==baseform) ||
			(strstr(baseform, "FORWARD-")==baseform) ||
			(strstr(baseform, "THROUGH-")==baseform) ||
			(strstr(baseform, "INSIDE-")==baseform) ||
			(strstr(baseform, "OUTSIDE-")==baseform) ||
			(strstr(baseform, "AROUND-")==baseform) ||
			(strstr(baseform, "OF-")==baseform) ||
			(strstr(baseform, "AT-")==baseform) ||
			(strstr(baseform, "INTO-")==baseform) ||
			(strstr(baseform, "ONTO-")==baseform) ||
			(strstr(baseform, "ALONG-")==baseform) ||
			(strstr(baseform, "ABOVE-")==baseform) ||
			(strstr(baseform, "OVER-")==baseform) ||
			(strstr(baseform, "WITH-")==baseform) ||
			(strstr(baseform, "BY-")==baseform) ||
			(strstr(baseform, "AS-")==baseform) ||
			(strstr(baseform, "AGAINST-")==baseform) ||
			(strstr(baseform, "ABOUT-")==baseform) ||
			(strstr(baseform, "NEAR-")==baseform) ||
			(strstr(baseform, "FOR-")==baseform) ||

			(strstr(baseform, "-THE-")) ||
		   (strstr(baseform, "-AND-")) ||
			(strstr(baseform, "-OR-")) ||
			(strstr(baseform, "-FOR-")) ||
			(strstr(baseform, "-IN-")) ||
			(strstr(baseform, "-ON-")) ||
			(strstr(baseform, "-UP-")) ||
			(strstr(baseform, "-DOWN-")) ||
			(strstr(baseform, "-AWAY-")) ||
			(strstr(baseform, "-OFF-")) ||
			(strstr(baseform, "-UNDER-")) ||
			(strstr(baseform, "-OUT-")) ||
			(strstr(baseform, "-AFTER-")) ||
			(strstr(baseform, "-BEFORE-")) ||
			(strstr(baseform, "-TO-")) ||
			(strstr(baseform, "-FROM-")) ||
			(strstr(baseform, "-BACK-")) ||
			(strstr(baseform, "-FORWARD-")) ||
			(strstr(baseform, "-THROUGH-")) ||
			(strstr(baseform, "-INSIDE-")) ||
			(strstr(baseform, "-OUTSIDE-")) ||
			(strstr(baseform, "-AROUND-")) ||
			(strstr(baseform, "-ROUND-")) ||
			(strstr(baseform, "-OF-")) ||
			(strstr(baseform, "-AT-")) ||
			(strstr(baseform, "-INTO-")) ||
			(strstr(baseform, "-ONTO-")) ||
			(strstr(baseform, "-ALONG-")) ||
			(strstr(baseform, "-ABOVE-")) ||
			(strstr(baseform, "-OVER-")) ||
			(strstr(baseform, "-WITH-")) ||
			(strstr(baseform, "-BY-")) ||
			(strstr(baseform, "-THAN-")) ||
			(strstr(baseform, "-AS-")) ||
			(strstr(baseform, "-AGAINST-")) ||
			(strstr(baseform, "-ABOUT-")) ||
			(strstr(baseform, "-NEAR-")) ||
			(strstr(baseform, "-FOR-")) ||
			(strstr(baseform, "-IT-"))
		))
			continue;

		// get pronunciation
		p=cmuline+j;
		while ((*p==' ') || (*p==tab_char))
			p++;
		strcpy(wordpron, p);

		// fix CMU's "un-" pronunciation
		if (strncmp(baseform, "UN", 2)==0 && strncmp(wordpron, "AH0 N", 5)==0 && strncmp(baseform, "UNTIL", 5)!=0) {
			strcpy(workbuf, wordpron+4);
			strcpy(wordpron, "AHH0 ");
			strcat(wordpron, workbuf);
		}

		// fix Moby's "-ness" pronunciation
		if (strrstr(baseform, "NESS")==baseform+strlen(baseform)-4 &&
				(strrstr(wordpron, "N EH0 S")==wordpron+strlen(wordpron)-7 ||
				 strrstr(wordpron, "N IH0 S")==wordpron+strlen(wordpron)-7)
		    ) {
			if (strlen(baseform)>5)
				wordpron[strlen(wordpron)-5]='A';		
		}

		// fix Moby's "-nesses" pronunciation
		if (strrstr(baseform, "NESSES")==baseform+strlen(baseform)-6 &&
				(strrstr(wordpron, "N IH0 S IH0 Z")==wordpron+strlen(wordpron)-13 ||
				 strrstr(wordpron, "N IH0 S AH0 Z")==wordpron+strlen(wordpron)-13)
		    ) {
			if (strlen(baseform)>7)
				wordpron[strlen(wordpron)-11]='A';		
		}
		
		// fix Moby's "-less" pronunciation
		if (strrstr(baseform, "LESS")==baseform+strlen(baseform)-4 &&
				(strrstr(wordpron, "L EH0 S")==wordpron+strlen(wordpron)-7 ||
				 strrstr(wordpron, "L IH0 S")==wordpron+strlen(wordpron)-7)
			) {
			if (strlen(baseform)>5)
				wordpron[strlen(wordpron)-5]='A';		
		}

		// fix Moby's "-lessly" pronunciation
		if (strrstr(baseform, "LESSLY")==baseform+strlen(baseform)-6 &&
				(strrstr(wordpron, "L IH0 S L IY0")==wordpron+strlen(wordpron)-13)
			) {
			if (strlen(baseform)>7)
				wordpron[strlen(wordpron)-11]='A';		
		}

		// fix Moby's "-lessness" pronunciation
		if (strrstr(baseform, "LESSNESS")==baseform+strlen(baseform)-8 &&
				(strrstr(wordpron, "L IH0 S N AH0 S")==wordpron+strlen(wordpron)-15)
			) {
			if (strlen(baseform)>9)
				wordpron[strlen(wordpron)-13]='A';		
		}


		// fix Moby's "-ful" pronunciation
		if (strrstr(baseform, "FUL")==baseform+strlen(baseform)-3 &&
				(strrstr(wordpron, "F UH0 L")==wordpron+strlen(wordpron)-7)
			) {
			if (strlen(baseform)>4)
				wordpron[strlen(wordpron)-5]='A';		
		}

		// fix Moby's "-fuls" pronunciation
		if (strrstr(baseform, "FULS")==baseform+strlen(baseform)-4 &&
				(strrstr(wordpron, "F UH0 L Z")==wordpron+strlen(wordpron)-9)
			) {
			if (strlen(baseform)>5)
				wordpron[strlen(wordpron)-7]='A';		
		}

		// fix Moby's "-fully" pronunciation
		if (strrstr(baseform, "FULLY")==baseform+strlen(baseform)-5 && strlen(baseform)>6) {
			if (strrstr(wordpron, "F UH0 L IY0")==wordpron+strlen(wordpron)-11)
				wordpron[strlen(wordpron)-9]='A';
			else if (strrstr(wordpron, "F UH0 L L IY0")==wordpron+strlen(wordpron)-13)
				wordpron[strlen(wordpron)-11]='A';
		}

		// fix Moby's "-fulness" pronunciation
		if (strrstr(baseform, "FULNESS")==baseform+strlen(baseform)-7 &&
				(strrstr(wordpron, "F UH0 L N AH0 S")==wordpron+strlen(wordpron)-15)
			) {
			if (strlen(baseform)>8)
				wordpron[strlen(wordpron)-13]='A';		
		}
		
		// append a space to pron
		i=strlen(wordpron);
		if (wordpron[i-1]!=' ') {
			wordpron[i]=' ';
			wordpron[i+1]=0;
		}

		// calculate wordupron
		i=strlen(wordpron);
		j=0;

		for (k=0; k<i; k++) {
			if ((wordpron[k]>='0') && (wordpron[k]<='2'))
				continue;
			wordupron[j]=wordpron[k];
			j++;
		}
		wordupron[j]=0;
		wordupronlen=strlen(wordupron);

		if (wordupronlen>0)
			begins_with_vowel=if_begins_with_vowel();

		printf("WORD: %s....PV#: %d....WORDPRON: %s....WORDUPRON: %s....\n", baseform, pvn, wordpron, wordupron);

		nwords++;

		if (strcmp(prevword, baseform)==0) { // same word as previous one
			multipie=1;

			if (search(0, 0, 0)) {
				assemble_pie();
				nsucc++;

				if (strcmp(goodpie, "")==0)
					strcpy(goodpie, wordpie);
			}
			else
				printf("%s ", baseform);
		}
		else { // new word
			// print out prevword and prevword's goodpie
			if (strcmp(prevword, "")!=0) {
				if (strcmp(goodpie, "")==0) {
					if (strstr(prevword, "-")==NULL) {
						strcpy(workbuf, "");
						if (begins_with_vowel)
							strcat(workbuf, "{");
						fprintf(pief, "\t\"%s\": \"%s\",\n", prevword, workbuf);
					}
				}
				else {
					fprintf(pief, "\t\"%s\": \"%s\",\n", prevword, goodpie);
					//					if (multipie)
					//						fprintf(pief, "*");
				}
			}

			// set new prevword and goodpie
			strcpy(prevword, baseform);
			multipie=0;

			if (search(0, 0, 0)) {
				assemble_pie();
				nsucc++;
				strcpy(goodpie, wordpie);
			}
			else {
				strcpy(goodpie, "");
				printf("%s ", baseform);
			}
		}
	}

	// print out prevword and prevword's goodpie
	if (strcmp(prevword, "")!=0) {
		if (strcmp(goodpie, "")==0) {
			if (strstr(prevword, "-")==NULL) {
				strcpy(workbuf, "");
				if (begins_with_vowel)
					strcat(workbuf, "{");
				fprintf(pief, "\t\"%s\": \"%s\"\n", prevword, workbuf);
			}
		}
		else {
			fprintf(pief, "\t\"%s\": \"%s\"\n", prevword, goodpie);
			//					if (multipie)
			//						fprintf(pief, "*");
		}
	}

	fprintf(pief, "};\n");

	printf("\n\n%d out of %d words resolved (%.1f%%).\n", nsucc, nwords, (double)nsucc/(double)nwords*100);

	fclose(cmuf);
	fclose(pief);

	freefrags();

	return 0;
}
