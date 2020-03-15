import string
import re
from collections import defaultdict

AUTHORS = ["Mickiewicz", "Prus", "Sienkiewicz"]

def count_words():
    allwords = [0,0,0]
    words_author = [defaultdict(int),defaultdict(int),defaultdict(int)]
    for i, author in enumerate(AUTHORS):
        f = open(author + ".txt","r")
        tekst = f.read()
        for p in string.punctuation + "1234567890":
            tekst = tekst.replace(p, " ")
        tekst = tekst.lower().split()
        tekst = [w for w in tekst if w]
        f.close()
        for word in tekst:
            words_author[i][word] += 1
            allwords[i] += 1
            
    return words_author, allwords

def tfidf_create():
    tfidf = {}
    words_author,allwords = count_words()
    for word in (set(words_author[0].keys()) | set(words_author[1].keys()) | set(words_author[2].keys())):
        val = [words_author[i][word]/allwords[i] for i in range(3)]
        tfidf[word] = [value/sum(val) for value in val]
    return tfidf, words_author

def normalization(tfidf,words_author):
    rel = []
    for word in tfidf.keys():
        reliability = sum([(tfidf[word][i] - 1/3) ** 2 for i in range(3)])
        reliability *= sum([words_author[i][word] for i in range(3)])
        rel.append((reliability, word))
    rel.sort(reverse=True)
    rel = rel[:500]
    return rel

def encode_tfidf():
    tfidf, words_author = tfidf_create()
    wynik = ""
    rel = normalization(tfidf, words_author)
    for _, word in rel:
        wynik += str(word)
        for i in range(3):
            wynik += ","
            if tfidf[word][i] < 0.01:
                wynik += "1"
            else:
                wynik += str(int(tfidf[word][i]*100))
        wynik += ";"
    wynik = wynik[:-1]
    return wynik

print(encode_tfidf())
"""
tfidf, _ = tfidf_create()
with open("test.in") as f:
    lines = f.readlines()

new = []
for l in lines[1:]:
    for p in string.punctuation + "1234567890":
        l = l.replace(p, " ")
    l = l.lower().split()
    l = [w for w in l if w]
    new.append(l)


answers= []
for l in new:
    scores = [1, 1, 1]
    for w in l:
        if w in tfidf.keys():
            for i in range(3):
                scores[i] *= tfidf[w][i]

    print(scores)
    winner = None
    best = 0
    for i in range(3):
        if best < scores[i]:
            best = scores[i]
            winner = AUTHORS[i]

    answers.append(winner)
    print(winner)
    
with open("test.out") as f:
    gold = f.readlines()

acc = 0
for a, g in zip(answers, gold):
    if a == g[:-1]:
        acc += 1
    else:
        print(a, g[:-1])

print("Acc", acc/len(gold))"""
