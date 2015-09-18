#include "marcfile.h"

MarcFile::MarcFile(std::string filePath) {
		this->filePath = filePath;
		this->content = "";

		this->_getContent();
}

void MarcFile::_getContent() {
		std::ifstream f(filePath.c_str());

		if (!f.is_open()) {
				return;
		}

		std::getline(f, this->content);
		f.close();
}

Record MarcFile::next() {
		std::string delimiter;
		delimiter = (char) 29;

		size_t pos;
		if ((pos = this->content.find(delimiter)) != std::string::npos) {
				std::string raw_record = this->content.substr(0, pos);
				Record r;
				r.setRawData(raw_record);
				this->content.erase(0, pos + delimiter.length());
				return r;
		}

		//size_t pos = 0;
		//std::string raw_record;
		//while ((pos = content.find(delimiter)) != std::string::npos) {
		//		raw_record = content.substr(0, pos);
		//		Record r(raw_record);
		//		content.erase(0, pos + delimiter.length());
		//}
}

bool MarcFile::isValid() {
		if (this->content != "") {
				return false;
		}

		return true;
}
