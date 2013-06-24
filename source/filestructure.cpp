#include "filestructure.h"
#include "widgettextedit.h"
#include <QList>
#include <QTextBlock>

FileStructure::FileStructure(WidgetTextEdit *parent) :
    widgetTextEdit(parent),
    structureInfo(new QList<FileStructureInfo*>()),
    blockIndentations(new BlockIndentation[0])
{

}

void FileStructure::updateStructure()
{
    // clean memory
    foreach(FileStructureInfo * in,*this->structureInfo)
    {
        delete in;
    }
    this->structureInfo->clear();
    delete this->blockIndentations;
    this->blockIndentations = new BlockIndentation[this->widgetTextEdit->document()->blockCount()];

    int textBlockIndex = 0;
    FileStructureInfo * stru;
    int lastLevel[3];
    lastLevel[0] = lastLevel[1] = lastLevel[2] = -1;
    int level = 0;
    int lastBlock=0;
    QTextBlock textBlock = this->widgetTextEdit->document()->begin();
    bool first = true;
    do{

        if(textBlock.text().indexOf(QRegExp("\\\\(sub){0,2}section\\{[^\\}]*\\}"), 0) != -1 ||
                textBlock.text().indexOf(QRegExp("\\\\begin\\{thebibliography\\}"), 0) != -1)
        {
            for(int i = lastBlock; i < textBlockIndex; ++i)
            {
                this->blockIndentations[i].level = level;
                this->blockIndentations[i].next = textBlockIndex;
            }
            level = textBlock.text().indexOf(QRegExp("\\\\subsubsection\\{[^\\}]*\\}"), 0) != -1 ? 3 : textBlock.text().indexOf(QRegExp("\\\\subsection\\{[^\\}]*\\}"), 0) != -1 ? 2 : 1;
            for(int i = level; i <= 3; ++i)
            {
                if(lastLevel[i - 1] != -1)
                {
                    this->structureInfo->at(lastLevel[i - 1])->endBlock = textBlockIndex - 1;
                    lastLevel[i - 1] = -1;
                }
            }
            lastBlock = textBlockIndex;
            lastLevel[level - 1] = this->structureInfo->count();
            first = false;
            QString s = textBlock.text();
            stru = new FileStructureInfo;
            stru->startBlock = textBlockIndex;
            stru->endBlock = this->widgetTextEdit->document()->blockCount() - 1;
            stru->name = textBlock.text().indexOf(QRegExp("\\\\(sub){0,2}section\\{[^\\}]*\\}"), 0) != -1 ? s.replace(QRegExp(".*\\\\(sub){0,2}section\\{([^\\}]*)\\}.*"), "\\2") : "Bibliography";
            stru->level = level;
            this->structureInfo->append(stru);
        }
        textBlock = textBlock.next();
        ++textBlockIndex;
    }while(textBlockIndex < this->widgetTextEdit->document()->blockCount());

    for(int i = lastBlock; i < this->widgetTextEdit->document()->blockCount(); ++i)
    {
        this->blockIndentations[i].level = level;
        this->blockIndentations[i].next = this->widgetTextEdit->document()->blockCount();
    }

    return;

    first = true;
    textBlockIndex = 0;
    textBlock = this->widgetTextEdit->document()->begin();
    do{
        if(textBlock.text().indexOf(QRegExp("\\\\subsection\\{[^\\}]*\\}"), 0) != -1)
        {
            if(!first)
            {
                this->structureInfo->last()->endBlock = textBlockIndex-1;
            }
            level = 2;
            first = false;
            QString s = textBlock.text();
            stru = new FileStructureInfo;
            stru->startBlock = textBlockIndex;
            stru->endBlock = this->widgetTextEdit->document()->blockCount() - 1;
            stru->name = s.replace(QRegExp(".*\\\\subsection\\{([^\\}]*)\\}.*"), "\\1");
            stru->level = level;
            this->structureInfo->append(stru);
        }
        textBlock = textBlock.next();
        ++textBlockIndex;
    }while(textBlockIndex < this->widgetTextEdit->document()->blockCount());
    first = true;
    textBlockIndex = 0;
    textBlock = this->widgetTextEdit->document()->begin();
    do{
        if(textBlock.text().indexOf(QRegExp("\\\\subsubsection\\{[^\\}]*\\}"), 0) != -1)
        {
            if(!first)
            {
                this->structureInfo->last()->endBlock = textBlockIndex-1;
            }
            level = 3;
            first = false;
            QString s = textBlock.text();
            stru = new FileStructureInfo;
            stru->startBlock = textBlockIndex;
            stru->endBlock = this->widgetTextEdit->document()->blockCount() - 1;
            stru->name = s.replace(QRegExp(".*\\\\subsubsection\\{([^\\}]*)\\}.*"), "\\1");
            stru->level = level;
            this->structureInfo->append(stru);
        }
        textBlock = textBlock.next();
        ++textBlockIndex;
    }while(textBlockIndex < this->widgetTextEdit->document()->blockCount());
}
