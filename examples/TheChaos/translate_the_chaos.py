# -*- coding: utf-8 -*-
"""
A script to translate The Chaos into phonetic english alphabets

This imports the poem, translates to "arpbet" using the CMU dictionary. 

Then it uses a table to translate arpbet to IPA, then to multiple other 
phonetic alphabets.
"""

import nltk
import codecs
# Import tables parsed from wikipedia
import pickle
ipa2X=pickle.load(open('ipa2X.dat'))
arp2ipa=pickle.load(open('arp2ipa.dat'))

# 1.translate text to phonetic english using CMUDict
nltk.download('cmudict')
cmu=nltk.corpus.cmudict.dict()

def rev_upper(origWord,modWord,newWord):
    """A helper function to lower a word, then undo it on another word"""
    # is the word lower, upper or cap?
    if modWord.upper()==origWord:
        op=unicode.upper
        return [op(l) for l in newWord]
    elif modWord.capitalize()==origWord:
        op=unicode.lower
        newWord=[op(l) for l in newWord]
        newWord[0]=newWord[0].upper()
        return newWord
    else:
        op=unicode.lower # lower if we arn't sure
        return [op(l) for l in newWord]

    
inputTxt=codecs.open('TheChaos.txt','r').readlines()

alphabets=ipa2X[ipa2X.keys()[0]].keys()
alphabets.pop(-1) # Not examples column
for AKey in alphabets:
    print "\n################\n"+AKey
    outTxt=''
    missing=[]
    for line in inputTxt:
        words=nltk.tokenize.word_tokenize(line)
        for word in words:
            word_lc=word.lower()
            if word_lc in cmu:
                word_AM=cmu[word_lc][0] # if multiple results we take the first
                word_IPA=[arp2ipa[l] for l in word_AM] # convert to ipa
                
                # attempt to convert to Akey
                WORD_RSc=[]
                for w in word_IPA:
                    try:
                        w=ipa2X[w][AKey]
                    except:
                        if w not in missing:
                            missing.append(w)
                    WORD_RSc.append(w)
                    
                # change case back
                word_ph=rev_upper(word,word_lc,WORD_RSc)
                
                # replace word
                line=line.replace(word,''.join(word_ph))
        outTxt+=line
    print "Letters missing from alphabet:",AKey,' '.join(missing)
    print outTxt
    codecs.open('TheChaos_{}.txt'.format(AKey),'w').write(outTxt)
