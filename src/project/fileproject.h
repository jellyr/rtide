#ifndef FILEPROJECT_H
#define FILEPROJECT_H

#include <QObject>
#include <QSharedData>

#include "fileprojectinfo.h"
#include "version/abstractversioncontrol.h"

class Editor;

class FileProjectData : public QSharedData
{
public:
    FileProjectInfo _info;
    Project *_project;

    AbstractVersionControl *_versionControl;
    FileVersionChange *_fileChange;
};

class FileProject : public QObject
{
    Q_OBJECT
public:
    FileProject(const QString &filePath, Project *project);

    const FileProjectInfo &info() const;

    QList<Editor *> openedEditors();

    // version control interface
    void valid(int line=-1);
    void checkout(int line=-1);
    void inValid(int line=-1);
    void updateDiff();

signals:
    void fileContentChanged();
    void versionStatusChanged();
    void versionDiffChanged();

protected:

private:
    Q_DISABLE_COPY(FileProject)
    //QSharedDataPointer<FileProjectData> _d;
    FileProjectInfo _info;
    Project *_project;

    AbstractVersionControl *_versionControl;
    FileVersionChange *_fileChange;
};

#endif // FILEPROJECT_H
