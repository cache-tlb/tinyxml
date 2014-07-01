#include "XMLDoc.h"
#include <iostream>

std::string input_filename;

double meanshift_sp;
double meanshift_sr;

int bilateral_size1;
int bilateral_size2;
double bilateral_sigma1;
double bilateral_sigma2;

double swt_canny_ratio;
bool swt_dark_on_light;

double segment_sigma;
double segment_c;
int segment_minsize;

double merge_color_thres;
double merge_swt_thres;

double swt_filter_variance_mean_ratio;

std::string ocr_lang;

#define print_variable(x) {std::cout << (#x) << " = " << x << std::endl;}

void load_config(char *config_file) {
    tixml::XMLDoc doc;
    doc.Load(config_file);
    input_filename = doc.get<std::string>("input.filename", 0);
    ocr_lang = doc.get<std::string>("input.language", 0);

    meanshift_sp = doc.get<double>("parameter.mean-shift.@sp", 0);
    meanshift_sr = doc.get<double>("parameter.mean-shift.@sr", 0);

    bilateral_size1 = doc.get<int>("parameter.bilateral.@size1", 0);
    bilateral_size2 = doc.get<int>("parameter.bilateral.@size2", 0);
    bilateral_sigma1 = doc.get<double>("parameter.bilateral.@sigma1", 0);
    bilateral_sigma2 = doc.get<double>("parameter.bilateral.@sigma2", 0);

    swt_canny_ratio = doc.get<double>("parameter.swt.@canny-non-edge-ratio", 0);
    swt_dark_on_light = doc.get<int>("parameter.swt.@dark-on-light", 0);
    swt_filter_variance_mean_ratio = doc.get<double>("parameter.swt.@fliter-variance-mean-ratio", 0);

    segment_sigma = doc.get<double>("parameter.segment.@sigma", 0);
    segment_c = doc.get<double>("parameter.segment.@c", 0);
    segment_minsize = doc.get<int>("parameter.segment.@min-size", 0);

    merge_color_thres = doc.get<double>("parameter.merge.@color-thres", 0);
    merge_swt_thres = doc.get<double>("parameter.merge.@swt-thres", 0);
}

int main() {
    tixml::XMLDoc doc;
    doc.Create("root");
    tixml::XMLNode* root = doc.getRoot();
    std::vector<tixml::XMLNode*> &root_children = root->children();
    for (int i = 0; i < 10; i++) {
        tixml::XMLNode* node = new tixml::XMLNode("node", "");
        node->setAttrib("type", "node");
        std::vector<tixml::XMLNode*> &node_children = node->children();
        for (int j = 0; j < 2; j++){
            tixml::XMLNode* leaf = new tixml::XMLNode("leaf", "");
            leaf->setAttrib("type", "leaf");
            node_children.push_back(leaf);
        }
        root_children.push_back(node);
    }
    doc.Save("example2.xml");
    return 0;

    /*load_config("config.xml");
    print_variable(input_filename);
    print_variable(meanshift_sp);
    print_variable(meanshift_sr);
    print_variable(bilateral_size1);
    print_variable(bilateral_size2);
    print_variable(bilateral_sigma1);
    print_variable(bilateral_sigma2);
    print_variable(swt_canny_ratio);
    print_variable(swt_dark_on_light);
    print_variable(segment_sigma);
    print_variable(segment_c);
    print_variable(segment_minsize);
    print_variable(merge_color_thres);
    print_variable(merge_swt_thres);
    print_variable(swt_filter_variance_mean_ratio);
    print_variable(ocr_lang);
    return 0;*/
}