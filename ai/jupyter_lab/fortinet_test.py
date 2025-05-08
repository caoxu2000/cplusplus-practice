from collections import Counter
def maxOccurChar(text: str):
  countDict = {}
  maxCount = 0
  maxOccurChar = ""

  for c in text:
    countDict[c] = 1 + countDict.get(c, 0)
  # countDict = Counter(text)
  # print(countDict)

  for c in text:
    if (countDict[c] > maxCount):
      maxCount = countDict[c]
      maxOccurChar = c

  return maxOccurChar


text = "baabbBbaacc"
maxOccurCharacter = maxOccurChar(text)
print("Max occurred character is " + maxOccurCharacter)