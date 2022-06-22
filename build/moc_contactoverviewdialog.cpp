/****************************************************************************
** Meta object code from reading C++ file 'contactoverviewdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../00_WIP/OpenPointList-Application/src/contactoverviewdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactoverviewdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ContactOverviewDialog_t {
    const uint offsetsAndSize[28];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ContactOverviewDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ContactOverviewDialog_t qt_meta_stringdata_ContactOverviewDialog = {
    {
QT_MOC_LITERAL(0, 21), // "ContactOverviewDialog"
QT_MOC_LITERAL(22, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(46, 0), // ""
QT_MOC_LITERAL(47, 21), // "tableSelectionChanged"
QT_MOC_LITERAL(69, 14), // "QItemSelection"
QT_MOC_LITERAL(84, 8), // "selected"
QT_MOC_LITERAL(93, 30), // "on_RemoveContactButton_clicked"
QT_MOC_LITERAL(124, 28), // "on_EditContactButton_clicked"
QT_MOC_LITERAL(153, 27), // "on_AddContactButton_clicked"
QT_MOC_LITERAL(181, 22), // "on_tableView_activated"
QT_MOC_LITERAL(204, 11), // "QModelIndex"
QT_MOC_LITERAL(216, 5), // "index"
QT_MOC_LITERAL(222, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(248, 25) // "on_pushButtonLoad_clicked"

    },
    "ContactOverviewDialog\0on_actionLoad_triggered\0"
    "\0tableSelectionChanged\0QItemSelection\0"
    "selected\0on_RemoveContactButton_clicked\0"
    "on_EditContactButton_clicked\0"
    "on_AddContactButton_clicked\0"
    "on_tableView_activated\0QModelIndex\0"
    "index\0on_pushButtonSave_clicked\0"
    "on_pushButtonLoad_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactOverviewDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    1,   63,    2, 0x08,    2 /* Private */,
       6,    0,   66,    2, 0x08,    4 /* Private */,
       7,    0,   67,    2, 0x08,    5 /* Private */,
       8,    0,   68,    2, 0x08,    6 /* Private */,
       9,    1,   69,    2, 0x08,    7 /* Private */,
      12,    0,   72,    2, 0x08,    9 /* Private */,
      13,    0,   73,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ContactOverviewDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContactOverviewDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionLoad_triggered(); break;
        case 1: _t->tableSelectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1]))); break;
        case 2: _t->on_RemoveContactButton_clicked(); break;
        case 3: _t->on_EditContactButton_clicked(); break;
        case 4: _t->on_AddContactButton_clicked(); break;
        case 5: _t->on_tableView_activated((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: _t->on_pushButtonSave_clicked(); break;
        case 7: _t->on_pushButtonLoad_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    }
}

const QMetaObject ContactOverviewDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ContactOverviewDialog.offsetsAndSize,
    qt_meta_data_ContactOverviewDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ContactOverviewDialog_t
, QtPrivate::TypeAndForceComplete<ContactOverviewDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ContactOverviewDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactOverviewDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ContactOverviewDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ContactOverviewDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
