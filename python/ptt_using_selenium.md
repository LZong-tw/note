# ptt  using  selenium

##python3

```py
# -*- coding: utf-8 -*

from selenium import webdriver
from bs4 import BeautifulSoup
driver = webdriver.PhantomJS()
driver.get("https://www.ptt.cc/bbs/Gamesale/index.html")
soup = BeautifulSoup(driver.page_source, "lxml")
for article in soup.select('.r-list-container .r-ent .title a'):
    title = str(article.string)
    print(title)


```


## python2

```py
# -*- coding: utf-8 -*

from selenium import webdriver
from bs4 import BeautifulSoup
driver = webdriver.PhantomJS()
driver.get("https://www.ptt.cc/bbs/Gamesale/index.html")
soup = BeautifulSoup(driver.page_source, "lxml")
for article in soup.select('.r-list-container .r-ent .title a'):
    title = (article.string)
    print(title)


```


--- 

## ptt 18禁

點選 「我同意…」的按鈕後才可進入該版及閱讀文章 
於是大鳥絲瓜決定趁機玩玩看怎麼讓python點擊網頁中的按鈕

```html
#html
<form action="/ask/over18" method="post">
    <input type="hidden" name="from" value="/bbs/gossiping/index.html">
    <button class="btn-big" type="submit" name="yes" value="yes">我同意，我已年滿十八歲<br><small>進入</small></button>
    <button class="btn-big" type="submit" name="no" value="no">未滿十八歲或不同意本條款<br><small>離開</small></button>
</form>
```


### 安裝 geckodriver

```sh
https://github.com/mozilla/geckodriver/releases
$ sudo mv ./geckodriver /usr/local/bin/
$ sudo chmod a+x /usr/local/bin/geckodriver
```

### 執行 geckodriver 查看是否能正常運行。

```sh
$ geckodriver 
1476443497207	geckodriver	INFO	Listening on 127.0.0.1:4444

```


```py
# -*- coding: utf-8 -*

from selenium import webdriver
from bs4 import BeautifulSoup

driver = webdriver.Firefox()
driver.get("https://www.ptt.cc/bbs/Gossiping/index.html")
button = driver.find_element_by_class_name('btn-big')
button.click() # click 第一個抓到的 btn-big
soup = BeautifulSoup(driver.page_source)
print soup.text
driver.quit()
```




---

##  selenium 如何告訴PTT我已滿18

```py
# -*- coding: utf-8 -*

from selenium import webdriver
from bs4 import BeautifulSoup
driver = webdriver.PhantomJS()
driver.get("https://www.ptt.cc/bbs/Gossiping/index25664.html")
buttons = driver.find_elements_by_css_selector("div button[value='yes']")

for button in buttons:
    button.click()

driver.get("https://www.ptt.cc/bbs/Gossiping/index25664.html")
soup = BeautifulSoup(driver.page_source, "lxml")
#print soup.prettify()

for article in soup.select('.r-list-container .r-ent .title a'):
    title = (article.string)
    print(title)
```

## TODO

```py
# -*- coding: utf-8 -*
import sys
from selenium import webdriver
from bs4 import BeautifulSoup

driver = webdriver.PhantomJS()
driver.get("https://www.ptt.cc/ask/over18")
buttons = driver.find_elements_by_css_selector("div button[value='yes']")
for button in buttons:
    button.click()

def getPageNumber(content) :
    startIndex = content.find('index')
    endIndex = content.find('.html')
    pageNumber = content[startIndex+5 : endIndex]
    return pageNumber

def PageCount(PttName):
    driver.get('https://www.ptt.cc/bbs/'+PttName+'/index.html')
    soup = BeautifulSoup(driver.page_source, "lxml")
    ALLpageURL = soup.select('.btn.wide')[1]['href']
    ALLpage=int(getPageNumber(ALLpageURL))+1
    return  ALLpage

def crawler(PttName,ParsingPage):
    ALLpage=PageCount(PttName)
    #print ALLpage
    for number  in range(ALLpage, ALLpage-int(ParsingPage),-1):
        driver.get('https://www.ptt.cc/bbs/'+PttName+'/index'+str(number)+'.html')
        soup = BeautifulSoup(driver.page_source, "lxml")
        #print soup.prettify()
        for article in soup.select('.r-list-container .r-ent .title a'):
            title = (article.string)
            print(title)

if __name__ == "__main__":  
   PttName = str(sys.argv[1])
   ParsingPage = int(sys.argv[2])
   print 'Start parsing [',PttName,']....'
   crawler(PttName,ParsingPage)



```