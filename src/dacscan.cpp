#include "dacscan.h"

void DACScan::openFile() {
    file_contents = readFileIntoString(filename);
    std::stringstream spliter(file_contents);
    spliter.str(file_contents);
    std::string voltageKind;
    std::string order;
    std::string voltageValue;
    while (spliter >> voltageKind >> order >> voltageValue) {
        insertVoltageToVector(voltageKind, stoi(voltageValue));
    }
}

void DACScan::insertVoltageToVector(const std::string& voltageKind,
                                    int voltageValue) {
    Voltage vol = stoV(voltageKind);
    switch (vol) {
        case VRESETP:
            vresetp.push_back(voltageValue);
            break;
        case VRESETD:
            vresetd.push_back(voltageValue);
            break;
        case VCASP:
            vcasp.push_back(voltageValue);
            break;
        case VCASN:
            vcasn.push_back(voltageValue);
            break;
        case VPULSEH:
            vpulseh.push_back(voltageValue);
            break;
        case VPULSEL:
            vpulsel.push_back(voltageValue);
            break;
        case VCASN2:
            vcasn2.push_back(voltageValue);
            break;
        case VCLIP:
            vclip.push_back(voltageValue);
            break;
        case VTEMP:
            vtemp.push_back(voltageValue);
            break;
        case IAUX2:
            iaux2.push_back(voltageValue);
            break;
        case IRESET:
            ireset.push_back(voltageValue);
            break;
        case IDB:
            idb.push_back(voltageValue);
            break;
        case IBIAS:
            ibias.push_back(voltageValue);
            break;
        case ITHR:
            ithr.push_back(voltageValue);
            break;
        case NONAME:
            std::cout << "Strange voltage" << std::endl;
    }
}

TGraph* DACScan::drawGraph(std::vector<int>& arr) {
    TGraph* g1 = new TGraph();
    int i = 0;
    for (auto& elements : arr) {
        g1->SetPoint(i, i, elements);
        i++;
    }
    return g1;
}

void DACScan::printGraph() {
    graph.push_back(drawGraph(vresetp));
    graph.push_back(drawGraph(vresetd));
    graph.push_back(drawGraph(vcasp));
    graph.push_back(drawGraph(vcasn));
    graph.push_back(drawGraph(vpulseh));
    graph.push_back(drawGraph(vpulsel));
    graph.push_back(drawGraph(vcasn2));
    graph.push_back(drawGraph(vclip));
    graph.push_back(drawGraph(vtemp));
    graph.push_back(drawGraph(iaux2));
    graph.push_back(drawGraph(ireset));
    graph.push_back(drawGraph(idb));
    graph.push_back(drawGraph(ibias));
    graph.push_back(drawGraph(ithr));
    TCanvas* c1 = new TCanvas("c1", "c1", 1000, 800);
    TCanvas* c2 = new TCanvas("c2", "c2", 1400, 810);
    std::vector<TPad*> pad;
    TMultiGraph* merge = new TMultiGraph();
    TString padname;
    for (int i = 0; i < 14; i++) {
        padname = TString::Format("pad%d", i);
        if (i < 5) {
            TPad* pad1 =
                new TPad(padname, padname, 0.2 * i, 0.66, 0.2 * (i + 1), 1);
            pad.push_back(pad1);
        } else if (i < 10) {
            TPad* pad1 = new TPad(padname, padname, 0.2 * (i - 5), 0.33,
                                  0.2 * (i - 4), 0.66);
            pad.push_back(pad1);
        } else {
            TPad* pad1 = new TPad(padname, padname, 0.2 * (i - 10), 0,
                                  0.2 * (i - 9), 0.33);
            pad.push_back(pad1);
        }
        pad[i]->Draw();
        if (i < 9)
            graph[i]->SetLineColor(i + 1);
        else {
            graph[i]->SetLineStyle(9);
            graph[i]->SetLineColor(i - 8);
        }
        merge->Add(graph[i]);
    }
    c1->cd();
    merge->SetTitle("Summary plot");
    merge->GetXaxis()->SetTitle("DAC setting");
    merge->GetYaxis()->SetTitle("ADC");
    merge->Draw("APL");
    c1->SaveAs("DAC scan.png");
    std::string voltageName[14] = {
        "VRESETP", "VRESETD", "VCASP", "VCASN",  "VPULSEH", "VPULSEL", "VCASN2",
        "VCLIP",   "VTEMP",   "IAUX2", "IRESET", "IDB",     "IBIAS",   "ITHR"};
    c2->cd();
    for (int i = 0; i < 14; i++) {
        pad[i]->cd();
        graph[i]->SetTitle(voltageName[i].c_str());
        graph[i]->GetXaxis()->SetTitle("DAC setting");
        graph[i]->Draw("APL");
    }
    c2->SaveAs("DAC scan graphs.png");
}
