#include "powertest.h"

void PowerTest::openFile() {
    file_contents = readFileIntoString(filename);
    std::stringstream spliter(file_contents);
    spliter.str(file_contents);
    std::string time, time2, analog, analogUnit, digital, digitalUnit, status;
    spliter >> time >> analog >> analogUnit >> digital >> digitalUnit >>
        status;
    while (spliter >> time >> time2 >> analog >> digital >> status) {
        analogVoltage.push_back(stof(analog));
        digitalVoltage.push_back(stof(digital));
    }
}

void PowerTest::findMinMaxValues() {
    analogVoltageMax = *max_element(analogVoltage.begin(), analogVoltage.end());
    analogVoltageMin = *min_element(analogVoltage.begin(), analogVoltage.end());
    digitalVoltageMax =
        *max_element(digitalVoltage.begin(), digitalVoltage.end());
    digitalVoltageMin =
        *min_element(digitalVoltage.begin(), digitalVoltage.end());
}

bool PowerTest::isErrorPowerTest() {
    if (analogVoltageMin > 10 && analogVoltageMax < 20 &&
        digitalVoltageMin > 55 && digitalVoltageMax < 75)
        return true;
    else
        return false;
}

void PowerTest::printError() {
    if (isErrorPowerTest() == true)
        std::cout << "power test 이상없음" << std::endl;
    else
        std::cout << "power test 이상있음" << std::endl;
}

void PowerTest::printGraph(int binNumber) {
    if (isErrorPowerTest() == true) {
        TCanvas* c1 = new TCanvas("c1", "c1", 1000, 800);
        TCanvas* c2 = new TCanvas("c2", "c2", 1000, 800);
        TH1F* h1 = new TH1F("h1", "h1", binNumber,
                            static_cast<int>(analogVoltageMin) - 1,
                            static_cast<int>(analogVoltageMax) + 2);
        TH1F* h2 = new TH1F("h2", "h2", binNumber,
                            static_cast<int>(digitalVoltageMin) - 1,
                            static_cast<int>(digitalVoltageMax) + 2);

        for (int i = 0; i < file_contents.length() / 82; i++) {
            h1->Fill(analogVoltage[i]);
            h2->Fill(digitalVoltage[i]);
        }
        c1->cd();
        h1->SetTitle("Power test - Analog Current");
        h1->GetXaxis()->SetTitle("Analog Current[mA]");
        gStyle->SetOptStat(0);
        h1->Draw();
        c1->SaveAs("Analog current in power test.png");
        c2->cd();
        h2->SetTitle("Power test - Digital Current");
        h2->GetXaxis()->SetTitle("Digital Current[mA]");
        gStyle->SetOptStat(0);
        h2->Draw();
        c2->SaveAs("Digital current in power test.png");
    }
}
