#pragma once
#include <gtest/gtest.h>
//
#include <QApplication>
#include <QBoxLayout>
#include <QColor>
//
#include "View/CheckBoxView.h"
#include "View/Colors.h"
#include "View/Metrics.h"
#include "View/Qu.h"

#define GTEST_QT_TEST(suite_name, name)                                   \
    void suite_name##name##_scope(QWidget* root, QVBoxLayout*);           \
    GTEST_TEST(suite_name, name)                                          \
    {                                                                     \
        using namespace Rt2;                                              \
        int          argc = 0;                                            \
        QApplication app(argc, nullptr);                                  \
        Rt2::View::Qu::initResources(app);                                \
        QWidget* root;                                                    \
        {                                                                 \
            using namespace Rt2::View;                                    \
            const auto box = Qu::box(nullptr, Colors::CtrlBackground);    \
            box->setMinimumSize(Metrics::minWindow);                      \
            Qu::setBackground(box, Colors::CtrlBackground);               \
            box->setUpdatesEnabled(true);                                 \
            box->setMouseTracking(true);                                  \
            QVBoxLayout* layout = new QVBoxLayout();                      \
            box->setLayout(layout);                                       \
            root = box;                                                   \
        }                                                                 \
        try                                                               \
        {                                                                 \
            suite_name##name##_scope(root, (QVBoxLayout*)root->layout()); \
        }                                                                 \
        catch (Rt2::Exception&)                                           \
        {                                                                 \
        }                                                                 \
        delete root;                                                      \
    }                                                                     \
    void suite_name##name##_scope(QWidget* root, QVBoxLayout* layout)