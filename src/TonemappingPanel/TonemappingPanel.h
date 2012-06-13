/**
 * This file is a part of Luminance HDR package.
 * ----------------------------------------------------------------------
 * Copyright (C) 2006,2007 Giuseppe Rota
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * ----------------------------------------------------------------------
 *
 * Original Work
 * @author Giuseppe Rota <grota@users.sourceforge.net>
 * Improvements, bugfixing
 * @author Franco Comida <fcomida@users.sourceforge.net>
 *
 */

#ifndef TONEMAPPINGWIDGET_H
#define TONEMAPPINGWIDGET_H

#include <QStatusBar>

#include "Core/TonemappingOptions.h"
#include "Libpfs/frame.h"

class Gang;

namespace Ui
{
    class TonemappingPanel;
}

class TonemappingPanel: public QWidget
{
    Q_OBJECT

protected:
    Gang
            //mantiuk06
            *contrastfactorGang,
            *saturationfactorGang,
            *detailfactorGang,
            // mantiuk08
            *colorSaturationGang,
            *contrastEnhancementGang,
            *luminanceLevelGang,
            // fattal02
            *alphaGang,
            *betaGang,
            *saturation2Gang,
            *noiseGang,
            // *oldFattalGang,
            *fftSolverGang,
            // ashikhmin02
            *contrastGang,
            *simpleGang,
            *eq2Gang,
            // drago03
            *biasGang,
            // durand02
            *spatialGang,
            *rangeGang,
            *baseGang,
            // pattanaik00
            *multiplierGang,
            *coneGang,
            *rodGang,
            *autoYGang,
            *pattalocalGang,
            // reinhard02
            *keyGang,
            *phiGang,
            *range2Gang,
            *lowerGang,
            *upperGang,
            *usescalesGang,
            // reinhard05
            *brightnessGang,
            *chromaticGang,
            *lightGang,
            //
            *pregammaGang;

    TMOperator currentTmoOperator;
    TonemappingOptions *toneMappingOptions;
	QList<TonemappingOptions *> toneMappingOptionsToDelete;
    QVector<int> sizes;
    void fillToneMappingOptions();
    void setupUndo();
    void fromGui2Txt(QString destination); //i.e. WRITE tmo settings to text file
    //QString recentPathLoadSaveTmoSettings;
    QString tmoSettingsFilename;
    int out_ldr_cs;

    float heightToWidthRatio;
    bool adding_custom_size;

    void createDatabase();

    QScopedPointer<Ui::TonemappingPanel> m_Ui;

protected Q_SLOTS:
	virtual void changeEvent(QEvent* event);
    void on_pregammadefault_clicked();
    void on_defaultButton_clicked();
    void on_applyButton_clicked();
    void on_undoButton_clicked();
    void on_redoButton_clicked();
    void on_savesettingsbutton_clicked();
    void on_loadsettingsbutton_clicked();
    //APPLY tmo settings from text file
    void fromTxt2Gui();
    //user wants a custom size.
    void on_addCustomSizeButton_clicked();
    void fillCustomSizeComboBox();
    void updateCurrentTmoOperator(int);
    void updateUndoState();
	void loadParameters();
	void saveParameters();
	void loadComments();
	void execMantiuk06Query(bool, float, float,	float, QString);
	void execMantiuk08Query(float, float, float, bool, QString);
	void execAshikhminQuery(bool, bool, float, QString);
	void execDragoQuery(float, QString);
	void execDurandQuery(float, float, float, QString);
	void execFattalQuery(float, float, float, float, bool, QString);
	void execPattanaikQuery(bool, bool, float, float, float, QString);
	void execReinhard02Query(bool, float, float, int, int, int, QString);
	void execReinhard05Query(float, float, float, QString);

public:
    TonemappingPanel(QWidget *parent = 0);
    ~TonemappingPanel();
    void setSizes(int, int);
	bool replaceLdr();

public Q_SLOTS:
    void setEnabled(bool);
    void updatedHDR(pfs::Frame*);
    void updateTonemappingParams(TonemappingOptions *opts);

signals:
    void startTonemapping(TonemappingOptions*);

};

#endif
