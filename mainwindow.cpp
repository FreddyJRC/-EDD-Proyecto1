#include "mainwindow.h"
#include "ui_mainwindow.h"

QLabel **nivel0, **nivel1, **nivel2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* nivel0[8][8] = {{ui->label_18, ui->label_19, ui->label_20, ui->label_21, ui->label_22, ui->label_23, ui->label_24, ui->label_25},
                          {ui->label_26, ui->label_27, ui->label_28, ui->label_29, ui->label_30, ui->label_31, ui->label_32, ui->label_33},
                          {ui->label_34, ui->label_35, ui->label_36, ui->label_37, ui->label_38, ui->label_39, ui->label_40, ui->label_41},
                          {ui->label_42, ui->label_43, ui->label_44, ui->label_45, ui->label_46, ui->label_47, ui->label_48, ui->label_49},
                          {ui->label_50, ui->label_51, ui->label_52, ui->label_53, ui->label_54, ui->label_55, ui->label_56, ui->label_57},
                          {ui->label_58, ui->label_59, ui->label_60, ui->label_61, ui->label_62, ui->label_63, ui->label_64, ui->label_65},
                          {ui->label_66, ui->label_67, ui->label_68, ui->label_69, ui->label_70, ui->label_71, ui->label_72, ui->label_73},
                          {ui->label_74, ui->label_75, ui->label_76, ui->label_77, ui->label_78, ui->label_79, ui->label_80, ui->label_81}};

    QLabel* nivel1[8][8] = {{ui->label_99, ui->label_100, ui->label_101, ui->label_102, ui->label_103, ui->label_104, ui->label_105, ui->label_106},
                            {ui->label_107, ui->label_108, ui->label_109, ui->label_110, ui->label_111, ui->label_112, ui->label_113, ui->label_114},
                            {ui->label_115, ui->label_116, ui->label_117, ui->label_118, ui->label_119, ui->label_120, ui->label_121, ui->label_122},
                            {ui->label_123, ui->label_124, ui->label_125, ui->label_126, ui->label_127, ui->label_128, ui->label_129, ui->label_130},
                            {ui->label_131, ui->label_132, ui->label_133, ui->label_134, ui->label_135, ui->label_136, ui->label_137, ui->label_138},
                            {ui->label_139, ui->label_140, ui->label_141, ui->label_142, ui->label_143, ui->label_144, ui->label_145, ui->label_146},
                            {ui->label_147, ui->label_148, ui->label_149, ui->label_150, ui->label_151, ui->label_152, ui->label_153, ui->label_154},
                            {ui->label_155, ui->label_156, ui->label_157, ui->label_158, ui->label_159, ui->label_160, ui->label_161, ui->label_162}};

    QLabel* nivel2[8][8] = {{ui->label_180, ui->label_181, ui->label_182, ui->label_183, ui->label_184, ui->label_185, ui->label_186, ui->label_187},
                            {ui->label_188, ui->label_189, ui->label_190, ui->label_191, ui->label_192, ui->label_193, ui->label_194, ui->label_195},
                            {ui->label_196, ui->label_197, ui->label_198, ui->label_199, ui->label_200, ui->label_201, ui->label_202, ui->label_203},
                            {ui->label_204, ui->label_205, ui->label_206, ui->label_207, ui->label_208, ui->label_209, ui->label_210, ui->label_211},
                            {ui->label_212, ui->label_213, ui->label_214, ui->label_215, ui->label_216, ui->label_217, ui->label_218, ui->label_219},
                            {ui->label_220, ui->label_221, ui->label_222, ui->label_223, ui->label_224, ui->label_225, ui->label_226, ui->label_227},
                            {ui->label_228, ui->label_229, ui->label_230, ui->label_231, ui->label_232, ui->label_233, ui->label_234, ui->label_235},
                            {ui->label_236, ui->label_237, ui->label_238, ui->label_239, ui->label_240, ui->label_241, ui->label_242, ui->label_243}};

}

MainWindow::~MainWindow()
{
    delete ui;
}
