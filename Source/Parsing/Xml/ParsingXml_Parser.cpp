﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Parser::ParsingXml.parser.txt

This file is generated by: Vczh Parser Generator
***********************************************************************/

#include "../Parsing.h"
#include "../ParsingDefinitions.h"
#include "../ParsingAutomaton.h"
#include "ParsingXml_Parser.h"

namespace vl
{
	namespace parsing
	{
		namespace xml
		{
/***********************************************************************
ParserText
***********************************************************************/

const wchar_t parserTextBuffer[] = 
L"\r\n" L""
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L"// AST"
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L""
L"\r\n" L"class Node"
L"\r\n" L"{"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Text : Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken content;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class CData : Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken content (XmlUnescapeCData);"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Attribute : Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken name\t\t\t\t\t\t\t\t\t@Color(\"AttName\");"
L"\r\n" L"\ttoken value (XmlUnescapeAttributeValue)\t\t@Color(\"AttValue\");"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Comment : Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken content (XmlUnescapeComment);"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Element : Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken name\t\t\t\t\t\t\t\t\t@Color(\"TagName\");"
L"\r\n" L"\ttoken closingName\t\t\t\t\t\t\t@Color(\"TagName\");"
L"\r\n" L"\tAttribute[] attributes;"
L"\r\n" L"\tNode[] subNodes (XmlMergeTextFragment);"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Instruction : Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken name\t\t\t\t\t\t\t\t\t@Color(\"TagName\");"
L"\r\n" L"\tAttribute[] attributes;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Document : Node"
L"\r\n" L"{"
L"\r\n" L"\tNode[] prologs;"
L"\r\n" L"\tElement rootElement;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L"// Lexer"
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L""
L"\r\n" L"token INSTRUCTION_OPEN = \"/</?\"\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token INSTRUCTION_CLOSE = \"/?/>\"\t\t@Color(\"Boundary\");"
L"\r\n" L"token COMPLEX_ELEMENT_OPEN = \"/<//\"\t\t@Color(\"Boundary\");"
L"\r\n" L"token SINGLE_ELEMENT_CLOSE = \"///>\"\t\t@Color(\"Boundary\");"
L"\r\n" L"token ELEMENT_OPEN = \"/<\"\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token ELEMENT_CLOSE = \"/>\"\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token EQUAL = \"/=\";"
L"\r\n" L""
L"\r\n" L"token NAME = \"[a-zA-Z0-9:._/-]+\"\t\t\t\t\t\t\t\t@ContextColor();"
L"\r\n" L"token ATTVALUE = \"\"\"[^<>\"\"]*\"\"|\'[^<>\']*\'\"\t\t\t\t\t\t@ContextColor();"
L"\r\n" L"token COMMENT = \"/</!--([^/->]|-[^/->]|--[^>])*--/>\"\t\t\t@Color(\"Comment\");"
L"\r\n" L"token CDATA = \"/</!/[CDATA/[([^/]]|/][^/]]|/]/][^>])*/]/]/>\";"
L"\r\n" L"token TEXT = \"([^<>=\"\"\' /r/n/ta-zA-Z0-9:._/-])+|\"\"|\'\";"
L"\r\n" L""
L"\r\n" L"discardtoken SPACE = \"/s+\";"
L"\r\n" L""
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L"// Rules"
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L""
L"\r\n" L"rule Attribute XAttribute = NAME:name \"=\" ATTVALUE:value as Attribute;"
L"\r\n" L"rule Text XText = (NAME:content | EQUAL:content | ATTVALUE:content | TEXT:content) as Text;"
L"\r\n" L"rule CData XCData = CDATA:content as CData;"
L"\r\n" L"rule Comment XComment = COMMENT:content as Comment;"
L"\r\n" L"rule Element XElement = \"<\" NAME:name {XAttribute:attributes} (\"/>\" | \">\" {XSubNode:subNodes} \"</\" NAME:closingName \">\") as Element;"
L"\r\n" L"rule Node XSubNode = !XText | !XCData | !XComment | !XElement;"
L"\r\n" L"rule Instruction XInstruction = \"<?\" NAME:name {XAttribute:attributes} \"?>\" as Instruction;"
L"\r\n" L"rule Document XDocument = {XInstruction:prologs | XComment:prologs} XElement:rootElement as Document;"
;

			vl::WString XmlGetParserTextBuffer()
			{
				return parserTextBuffer;
			}

/***********************************************************************
SerializedTable
***********************************************************************/

const vint parserBufferLength = 4442; // 18926 bytes before compressing
const vint parserBufferBlock = 1024;
const vint parserBufferRemain = 346;
const vint parserBufferRows = 5;
const char* parserBuffer[] = {
"\x00\x0E\x00\x02\x83\x80\x07\x7D\x00\x82\x03\xFF\x45\x08\x82\x83\x86\x81\x21\x6F\x6C\x2F\x32\x37\x84\x87\x02\x86\x00\x17\x82\x94\x21\x37\x32\x27\x30\x6D\x65\x06\x98\x8A\x80\x8E\x86\x00\x10\x92\x94\x98\x8A\x88\x85\x96\x8E\x1E\xA0\xA2\x95\x88\x85\x90\x87\x93\x29\x93\xB4\x84\x8D\x94\x9F\x81\x20\x74\x74\x1F\x81\x93\x94\x86\x9A\x84\x38\x91\xBA\x98\x88\x04\xA7\x9F\xA0\x56\x61\x2C\x35\x33\x9C\x93\x92\x82\x49\xAA\xBB\x83\x8D\x9C\xAF\x80\x98\x43\xD5\x86\xB7\xA3\x81\xAF\xA4\x86\x4D\xE8\x83\x82\x2F\x35\x3A\x36\x32\x61\x72\x39\x25\xA5\x9C\xB1\x87\x81\x39\xAB\xAA\xBB\xB0\x04\xB6\xB6\xB8\x72\xF4\x84\x87\xA8\xA8\xBE\xA4\xBD\x08\xE9\x89\xCB\xBD\xB7\xB5\xB9\xB9\x5B\x82\x84\xC5\xB6\xC2\xAE\xA6\xBE\x7E\x8E\xC1\xD1\xC5\x86\xB8\x00\xB3\x88\x84\x8A\xC2\xDC\xC7\xBF\xC6\xC1\x09\x9E\xE0\xDC\xC3\xD3\x82\xC5\xCC\x80\x90\xE4\x8C\x08\x8C\xDB\x87\x37\x6E\x74\x25\x38\x34\x39\xBC\x8D\x82\x9C\xFF\x76\xC8\x83\xE0\x89\xDD\xDD\xBD\x87\xFF\xC8\xD2\xCA\xD5\xCB\xB3\x2E\xAC\x86\xCD\x31\x91\xDD\xD6\x81\x09\x18\x99\xE2\x80\xA4\x3A\x39\x34\x62\x75\x3A\xDF\x74\xF5\xF0\xF2\xE7\x0F\xC4\x21\x34\x31\x36\xF2\xF3\xAE\x02\xAD\x90\x94\xE5\x31\xDE\xF7\xF2\xD7\x80\x0A\xC4\x2F\x33\x31\x3B\xEA\x74\x37\x74\x78\x7C\x19\x43\x45\x10\x1B\x65\x00\x82\x83\x3F\x0B\x18\x4D\x82\x40\x49\x2E\x13\x1E\x77\x75\x23\x14\x1D\x1A\xB8\x4B\x84\x00\x46\x1B\x82\x4E\x13\x1B\x64\x22\x42\x81\x87\x08\x64\x84\x14\x72\x0B\x8D\x0A\x77\x8A\xDC\x41\x5F\x75\x78\xBA\x64\x84\x40\x89\x6E\x32\x42\x00\x8B\x08\x5B\x70\x01\x77\x2F\xA2\x75\x18\x7A\x00\x36\x12\x54\x55\x03\x26\x46\x91\x7A\xEB\x61\x14\x81\x4B\x63\x38\x6A\x6E\x7D\x02\x8B\x93\x74\x80\x52\x82\x4D\x93\x71\x50\xB7\x79\x7F\x7E\xFD\x7F\x75\x7C\x1D\x55\x80\x00\x1E\x1C\x4A\x67\x13\x1F\x82\x5B\x83\x4C\x7E\x7F\x00\x8F\x88\x42\x9B\x64\xAF\x14\x1F\x81\x09\x9F\x9B\x81\x98\x74\x80\x8A\x00\x46\x7B\x82\x4B\x7A\x77\xE0\x7E\x87\x99\x94\xD2\x42\x49\x9F\x97\x6E\x84\x4E\x9B\x18\x12\x73\x19\x1A\x1B\x31\x61\x4C\x64\x9E\x08\x80\x82\x8F\x40\x34\xB2\x4F\x6C\xA5\x75\x96\x77\x64\x00\x73\x35\x12\x1B\x87\x21\x83\xA7\x7D\xA2\x03\x6E\x91\x87\x84\x72\x15\x87\x84\x6E\x7D\x88\x41\xAF\x9F\x3D\xBA\x66\xAA\x7B\xA8\x82\x4A\xAA\x84\x14\x96\x88\x86\x1B\x97\x82\x49\xA5\x48\xC1\x80\x05\xB2\x89\xC8\x61\x97\x97\x93\x01\x82\x80\x04\x46\x31\x18\x4F\xB3\x6F\xD4\xB5\x4B\x82\x80\xD5\x86\x57\xB7\x7D\xD9\x96\xBB\xB6\x79\xDD\x83\x6F\xB6\x79\xD3\x88\x45\xB9\x12\x4E\x13\x14\x16\x14\x55\x03\x14\x15\x12\x4F\x0E\x1F\x17\x13\x50\x05\x1E\x13\xB1\x03\x6F\x0C\x0F\x0B\x3F\x3F\x6E\x65\x04\x18\x40\xC0\x85\xBA\xEB\xAD\xBF\xB9\xBC\x5F\x03\x1C\x13\x13\x53\x05\x18\xBE\x40\xFC\xAF\x0E\x0C\x67\x06\x18\x44\x06\xC5\x78\x4F\x1D\x10\x14\x4C\x05\x18\x17\x17\x45\x1D\xCD\x12\xBD\x54\x33\xB5\xBF\xBD\x1C\xB9\xBB\xBF\x0B\x37\x96\x48\xC4\x43\x17\xC2\x43\x14\xBA\x47\x1D\xC0\xCA\xC8\x24\xC9\xCB\xC1\xC3\x0F\xC0\x0F\x0B\xCF\x3E\x05\x9C\x5C\x41\xC3\x44\xD6\x80\xCE\x4E\x25\xC4\xBE\xBD\x2D\xC8\x4D\xD2\xBE\xC5\xBA\x84\x42\x8A\x0C\x54\xD0\x01\xC8\x45\x23\xC9\xD2\xCE\x0C\xC5\x1D\xD0\x41\x4F\xFE\x0E\x65\xAC\x85\x77\x46\x81\x14\x55\x01\x1C\x13\xD7\x03\x4F\xDD\x0D\xC5\xDA\xB7\x7D\xCE\x13\x41\x23\xC2\xC0\x42\x77\xDB\x11\x19\x0B\x7A\x01\x1D\x0A\x16\x30\x2D\x09\x0E\x0E\x2E\x1F\x1F\x09\x0B\x5D\x2B\x04\x81\xAE\xFA\x5F\xA1\x10\x15\x54\x16\x1A\xD9\x15\x45\x13\x08\x46\xE5\x02\x62\x0B\x16\x17\x3C\x3E\x02\x09\x17\x2A\x22\x0C\x1F\x09\x9B\xDD\xE7\x08\xE8\x27\x39\x75\xD2\x57\x2E\xCF\x4A\xC6\xD6\x54\x22\x08\x46\xEC\x10\xFB\xB1\x09\x0B\x2D\x28\x0B\xE7\xE1\x3E\x1D\x1C\x1D\x0B\xBB\xED\x0D\xEF\xEF\xC0\xDE\x1D\xED\x0A\x2A\x38\xE2\xC6\xD4\x03\x56\xD5\xD8\x52\x78\x44\x1F\xE1\x10\x2C\x18\x45\xF5\xED\x2F\x21\x0F\x0B\x16\x43\x12\xF4\x15\x10\xDB\xFA\xEE\x17\x0B\x5D\x3E\xE4\xFB\xEE\xE5\xFC\x14\xFB\xF9\xC6\xDD\x18\xF3\xFA\x5D\x12\xC4\xD9\x42\x23\xA9\xCB\x46\xC7\x54\x24\x08\x46\xFE\x02\x62\xFD\xE5\x0F\x22\x07\x04\x08\x2F\x02\x0F\x17\x2E\x0F\x05\xEC\x3C\x6E\xDF\x00\x72\x70\xC2\x46\x70\x71\x29\x0B\x04\x1F\x22\x77\x04\xC6\x4B\x44\x33\x40\x53\x08\x14\x41\x03\x09\x22\x02\x68\x21\x1F\x8F\x07\x1C\x2B\x0B\x74\xC9\x02\x41\x5A\x0C\x30\x6C\x42\x2A\x88\x0B\xEE\x49\x4D\x5C\x04\x25\x5D\x0B\xEA\x3C\x3C\x17\x12\x0F\x0D\x72\x53\x08\x7B\x72\x04\x0E\xC6\x6E\x48\x08\x20\x04\x04\x0F\x33\x89\x48",
"\x1F\x2A\x84\x20\x2C\x8E\x84\x7B\x25\x80\x01\xE1\x04\x8D\x86\x3A\x91\x2C\x1D\x73\x72\x21\x58\x40\x8B\x88\x4A\x81\x0E\x11\x98\x29\x88\x1A\xA1\x09\x4D\x02\x2F\x89\x18\x2E\x01\x07\x11\x18\x26\x8C\x02\x38\x8A\x17\xBE\x0A\x06\x10\x1D\x7B\x7A\x20\x0D\x8F\xB2\x5F\x40\x05\x30\x33\x0E\x8D\x5E\x80\x0B\x11\x83\x2D\x8B\x24\x41\x24\x21\x7F\x80\x02\x18\xB6\x88\x87\x39\x6F\x2E\x87\x03\x22\x8A\x18\xBE\x00\x04\x20\x20\x8A\x90\x53\x02\x54\xA9\x65\x04\x8A\x00\x31\x50\x0B\x91\x83\x54\x88\x65\x04\x8D\x1A\x18\x26\x93\x69\x98\x92\x24\x9B\x9C\x8C\x10\x21\x00\x0B\x27\x5C\x34\x08\x7C\x06\x94\x31\xAB\x95\x95\xF3\x20\x43\x2B\xA7\x97\x51\xDC\x0E\x97\x53\x58\x15\x97\x14\xFC\x43\x21\x5C\x95\x57\x4B\x2E\x13\x06\x03\x11\x33\x99\x50\xBA\x95\x94\x22\x1C\x06\x08\x20\x04\x6F\x91\x71\x88\x04\x35\x41\x24\x08\x7B\x00\x04\x2C\x3C\x41\x50\xBA\x2F\x98\xAD\x58\x95\x0D\x3B\xBD\x08\x04\x28\x00\x06\x08\x12\x6B\x98\x56\xA2\x06\x73\x40\x94\x9A\x28\x9A\x91\x45\x67\xA1\x54\x9D\xDD\x80\x07\x37\xC9\x9F\x05\x65\x8D\x9D\x08\xCF\x8C\x53\x1B\x0E\x50\x53\xB0\x22\x9E\x73\x20\x09\x05\x1D\xF7\x8A\x97\x06\x0A\x03\x88\xC7\x8D\x8D\x32\xF6\x95\x6E\x7C\xAD\x89\x9A\x65\x13\x99\x35\xD7\x90\x47\x88\xAD\x8B\x9B\x15\xBE\x98\x38\xE2\x94\x9D\x57\xA7\x9B\x99\x40\x0A\x9D\x26\x93\x9E\x9D\x51\xA5\x52\x9E\xE2\x9B\x5C\x43\xCE\x92\x8F\x46\x4F\x51\x52\x11\xBF\xA1\x40\x83\xA0\x04\x5D\x8F\x93\x9D\x93\x90\x87\x40\x32\x83\xA5\x4D\x84\x92\x4E\x45\x0F\x2E\xF3\x4D\x79\x91\x21\xBD\xA1\x44\x8C\x97\x94\x5F\x3E\x9D\x53\x5D\x8C\x27\x92\xBA\x8E\x06\x0D\x06\x18\x22\xAA\x86\x9F\x97\xB9\x28\x9A\x32\xCC\x9D\xA1\x67\x90\xA2\xA2\xD6\x8E\x44\x37\xDA\x92\xAD\x8C\xA8\xA1\x9C\xE3\x80\xA2\x39\x80\xA2\xA4\x93\x96\xA0\x04\xEF\x93\x92\x46\xF4\x92\x04\x20\xB7\x99\x9F\x2E\xBD\x9E\x4C\x7F\x9B\x98\x81\xB6\x8D\xA6\x58\xB4\x0C\x90\x28\x99\x59\x42\x42\x91\x95\x74\x04\x8C\x16\x18\x2B\xB1\x50\x88\xB5\x94\x77\xB2\x8E\x93\x74\x8C\x95\x22\x28\x6A\x6D\xF9\x93\xB1\x6E\x2F\x9F\x71\xC8\x53\x76\xA1\x20\x13\x8F\x66\xAC\x94\x0A\xFC\x59\xB0\x4B\x74\x14\xA4\x62\xCA\xAB\x31\x30\xB1\x97\x4B\x95\x97\x93\x6B\xB9\x34\x8D\x14\x18\x26\xB6\xA1\x93\xB4\x1D\x25\x93\x09\xD7\x64\x67\xB4\xCC\x54\xA6\x6E\xAC\xB4\x35\x30\xBA\x91\xB6\xBD\x91\xA9\x0C\x56\xA8\x20\xE6\x88\xA1\xB0\x5A\xB5\xAC\x57\xAC\xA0\x9B\xBD\xAA\x9C\xA2\x3E\x44\xAC\xA0\x66\xAF\x9A\xB4\x9D\xA3\xAD\xCB\x8D\xAC\x3C\xA5\xA0\x9F\xB9\xAA\xA3\xBA\xA0\xBA\x9C\x3F\xB0\xAC\xAF\x99\xBF\xAE\xA6\xB8\x87\xB8\x2F\xC6\xB1\xB0\x17\x37\x04\xB9\x04\x2E\xB8\x53\x80\x41\xBA\xF4\x9E\xAE\xBA\x13\xA5\xAD\x76\x97\xA2\xC0\x5B\x67\xAC\xA3\x6A\xAD\xBE\x78\xA4\xAD\x8D\xB8\x9B\x96\xBC\xF5\x9E\xBD\x4B\xFB\x9F\xA5\xB0\x00\x8A\xA6\x7E\xA4\xA1\x60\x83\xB8\xB1\xA1\x82\x26\x6A\x84\xBC\x37\x4F\x86\x94\x0C\xE4\x82\x22\x91\x8F\xAD\x93\x4D\xBA\xBA\xA6\x81\x32\x82\xB7\x23\xC1\xA8\x19\x1E\xC0\x00\xAB\x4A\x92\xB7\x49\xAC\x78\x76\x3D\x9B\x4C\x2F\x79\x30\x91\x61\x9D\xC4\x80\x2E\x02\x06\x30\x18\x26\xC8\xA1\x82\xCB\x97\x25\x91\xA5\x6A\xAB\x55\x57\xAF\x4E\x0F\x33\xE3\x45\x4D\x3B\xAC\x95\x85\x6F\x14\x3F\x66\xED\x84\xCA\x89\x26\x48\xA5\xFB\xB4\x8D\x1B\xF1\x43\x4F\xC0\xB4\xA2\xC9\x9E\x4B\xAA\x7C\xCF\xA9\xB9\xFA\xB4\x05\x98\x08\x30\xCF\x73\xCD\xAD\xBF\xC8\x95\xBA\x9A\x4D\xC1\xAF\x76\x83\xC5\x8F\x02\xF1\x9D\xBB\x08\xC5\x9E\x82\xD5\x97\xA9\xB7\x8E\xC7\xA4\xF3\x87\xBE\x9D\xEA\xB5\xC3\xBD\x98\xC4\xA6\x05\xA7\xA1\x98\xD9\xAA\xA1\xAD\xB6\xC8\xA2\xE9\x81\xC3\x9E\xD9\x94\xC1\x4D\xFF\xCB\xA3\x69\xA2\xD2\x4C\x8B\xCB\x92\xF2\xB2\xA8\xA5\x74\xB2\xC1\x68\xF9\xAC\xBD\x47\xEF\xB9\xB0\x37\xAB\xCE\xAC\x6D\xCD\xA8\x22\xF8\xBB\x20\xFA\xA9\xA1\x4A\xAB\xA0\xB5\xAF\x97\xBE\xCF\xDA\xB5\x57\xA7\xDE\xB9\xC1\x51\xC4\xD6\xAD\xA6\xCF\xC0\xAA\x8A\xDD\xAB\x09\xEB\xBE\x9F\xAE\xDA\xC1\x53\xC0\x0C\x88\x27\x8F\xCD\x55\xBE\x58\x35\x20\x84\x21\x90\x2C\x17\xDE\x55\xBF\x44\x8D\x14\x18\x23\xDD\x50\x9F\xD9\xDB\x6E\x1A\xAB\x0F\x52\xB7\xD2\x00\xFA\xCA\xD8\xC1\xDC\x9B\x5C\xBF\x00\xA1\xBF\xA7\xD9\xCA\x26\xC2\x90\x76\xBA\x35\xDB\x5E\xBB\xDC\x93\x31\x1C\x04\x46\x02\xE1\x95\x7F\xD0\xB5\xD9\x77\xC5\x0F\x85\x80\x80\x05\xCE\x92\x74\x09\x94\x6F\x9A\x90\x53\x21\xA3\xBF\xBF\xD9\xD6\x81\xAD\xC4\x00\x32\x81\xAB\x1B\x80\xAA\xA8\x18\x36\xC7\x9C\xFC\xBD\x90\x1D\xC0\x02\x47\x58\x08\xCD\x0F\x8E\x4C\xC7\x2E",
"\x43\xC9\x06\x48\xC8\x21\xCC\xC3\x8A\xE5\x52\xAA\x9F\xDE\xBF\x53\xC8\x99\x5E\xC6\xCB\x6A\xBA\xB2\xE7\x55\xC0\xCE\x2E\xCF\x94\xCD\xA1\xFF\xAA\xE5\xD4\xD5\x35\x2F\xB8\xEA\xDA\x8C\x1D\xDC\xE9\x6E\x01\x98\x29\x18\x23\xEA\x73\xFC\x50\xDB\x51\xCA\xDC\xAF\xFF\xB8\xCF\x5F\xDE\xD1\xDE\xDC\xA2\x9C\xBD\xCB\x96\xDF\xAB\xE0\xD8\x37\x06\xA3\x88\xD4\xDA\xEA\xD4\x4C\xE0\xAF\xDF\x60\xE2\x50\xAA\xE3\xE4\xA6\xA8\xF9\xDF\xDD\xDC\x9D\xDD\x18\xFF\xD4\xC8\x82\xC8\x26\xEF\x43\x86\xE1\x1B\xED\xD2\x9A\x11\x00\x80\x88\x0E\xFF\xB2\xC4\xC3\x45\xE3\x3B\xBF\xDE\xE4\x28\xEA\xE7\xDD\x04\x27\x6F\x94\xEE\xE0\x98\x1E\xE4\xC7\xB6\x83\x21\x90\x45\xB5\xE5\x91\x7A\xE2\x90\xD4\x9B\xF2\x21\xA7\xE6\xE8\xDD\x44\xC5\xDC\x42\x2A\xFA\xED\xD3\xD9\xED\xD2\xEB\xCD\xEE\xBB\xF0\xED\xD2\x61\xF3\xDD\xDE\x77\x90\xE8\x10\x77\xEF\xDF\xD0\xF8\xED\xA2\xC1\x9E\xEC\x41\x00\xFF\xF6\x1F\x47\xE4\xBA\x5F\xA6\xF3\x32\x89\xF0\xE2\xD0\x93\xE4\x2A\x34\xBF\xDD\xD2\x8C\x26\xDA\xD7\xFF\x51\x66\x08\x38\xFA\xB7\xD6\xF8\x37\x18\xEF\x2B\xF2\x03\x37\x6E\x22\xEB\xED\x90\xDE\xFE\xCA\x02\x18\x28\xFF\xDE\xFE\xCE\xFA\x32\x0F\x00\x23\xEF\xE7\xC5\xE0\xFE\xC9\xA8\x8C\xCD\xAA\xFD\x08\x38\xFF\xA4\x89\xB9\xF3\x28\xBC\x84\xC6\x56\x30\x44\x8A\x47\x4C\xF6\x70\x20\xA4\x70\x10\xB4\x63\x64\xFE\x74\x07\xA1\x77\x45\xFB\x72\x36\x47\x27\x58\xC8\x11\x7F\x08\x14\x81\x21\x6C\x7F\x85\x4B\x80\xF9\x62\x80\x43\x4F\x58\x1C\x68\x1C\x40\x62\x81\x22\x6B\x80\x90\x73\x10\x0E\x8F\x58\xE6\x7E\x69\xD8\x74\x10\xDA\x7C\x77\xFD\x7B\x43\x74\x04\x81\x04\x14\x81\x1C\x85\x7C\xBA\x1E\x03\x29\x82\x6C\x1A\x72\x43\x7C\x7B\x80\x07\x81\x48\x0E\x86\x70\xBE\x70\x75\x16\x08\x11\x45\x81\x46\x50\x73\x62\x0B\x80\x7E\x02\x17\x37\x35\x8B\x76\x43\x8C\x7D\x6E\x08\x7F\x04\x1A\x7F\x49\x8B\x80\x3B\x86\x82\x20\x0D\x7A\xAC\x27\x76\xE9\x6B\x62\x59\x60\x20\x54\x83\x10\xFA\x70\x63\x2F\x82\x45\x00\x8A\x85\x37\x61\x86\x4B\x60\x86\x5A\x64\x07\x3F\x8D\x4B\x30\x6B\x80\x0D\x8B\x85\x58\x6F\x86\x3E\x05\x82\x41\x67\x79\xB9\x18\x39\x08\x1E\x87\x96\x7C\x26\x98\x79\x81\x30\x81\x87\x02\x15\x83\x35\x7A\x87\x82\x4A\x72\x32\x83\x10\x16\x8A\x72\x2E\x0B\x80\x69\x87\x88\x76\x85\x73\x37\x55\x68\x63\x82\x10\xFA\x75\x68\x4A\x80\x83\x93\x80\x00\x35\x85\x68\x3E\x07\x89\x6E\x56\x88\x90\x4E\x56\x91\x80\x83\x75\x86\x54\x6E\x5B\x45\x29\x42\x87\x5E\x4B\x62\x5E\x44\x64\x68\x48\x10\xB5\x8A\x46\x45\x4D\x46\x6F\x4F\x3D\xC0\x54\x47\x7F\x59\x45\xC4\x5E\x1A\x09\x80\x5B\xF3\x52\x48\x51\x55\x03\xB7\x62\x10\xB9\x60\x5D\x95\x6B\x75\x0F\x53\x7B\xC0\x65\x7B\xF2\x67\x60\xA1\x6E\x51\x6C\x57\x6C\xE3\x5D\x60\x6E\x50\x61\xCE\x8B\x6A\x14\x6A\x57\x85\x70\x50\x19\x60\x58\xD3\x6F\x81\xBC\x11\x26\x17\x84\x64\x8D\x58\x10\xEB\x8D\x81\xC8\x17\x7C\xE9\x5A\x59\xA9\x55\x59\x97\x5C\x04\xBD\x83\x5A\x0D\x70\x39\x0F\x71\x71\x92\x58\x5A\xAF\x45\x5A\xA8\x47\x8F\xA9\x5F\x57\xAB\x59\x83\x79\x7A\x74\xEB\x7E\x69\x2E\x04\x03\xC2\x73\x10\xC4\x72\x78\xB2\x75\x78\x0C\x7C\x7C\xFC\x80\x02\xCF\x7D\x78\x0D\x7E\x67\xD3\x74\x1C\x4B\x72\x85\xA6\x8B\x7D\x5D\x88\x7A\x34\x0A\x7A\x04\x1C\x7A\x20\x90\x65\xBF\x2C\x76\x84\x71\x51\x5E\x70\x6F\xD2\x81\x76\x22\x04\x77\x65\x71\x92\x51\x61\x8C\x02\x1A\x18\x77\x8A\x27\xC5\x89\x93\xC0\x42\x03\xB8\x58\x10\x3F\x98\x45\x6C\x84\x69\x6E\x4E\x5B\x49\x32\x90\xC2\x53\x94\x74\x00\x04\x8A\x81\x88\x3E\x6B\x72\x0C\x1E\x26\x4E\x93\x64\x33\x01\x73\x04\x13\x73\x53\x9B\x64\x6D\x47\x73\x52\x80\x74\x3C\x7F\x4A\x3C\x9B\x65\x20\x0D\x65\x6F\x0F\x65\xDF\x4B\x7F\x44\x75\x48\x46\x77\x47\x48\x79\x1F\x7B\x42\x10\x7D\x4C\x1E\x40\x29\x45\xE1\x24\x3F\x5A\x21\x5F\x81\x5C\x29\x00\x2F\x1B\x1C\x04\x12\x02\x26\x8E\x74\x0D\x33\x88\x5F\x1B\x1E\x0E\x97\xF7\x16\x90\x15\x5A\x88\xFF\x6F\x1B\x20\x06\x98\xEE\x11\x85\x34\x9F\x2B\x21\x80\x75\xBF\x14\x3B\xDE\x2E\x1E\x6E\x84\x25\x86\x5A\x5B\xBF\x1C\x3F\x97\x96\x1E\x4D\x9A\x72\x8F\x4A\x72\xBF\x16\x02\x8E\x96\x1E\xA4\x80\x4F\x73\x3B\x49\xBF\x18\x02\xA7\x95\x1E\x10\x0F\x41\x09\x11\x1C\xBF\x1C\x19\x75\x97\x9B\xB8\x9B\x1C\xC1\x17\x80\x6C\x39\x9B\x00\x0C\x19\xB6\x96\x58\x3E\x16\x25\xF2\x8F\x1B\x6F\x90\x00\x71\x91\x06\x92\x11\x1C\x9C\x12\x9B\xBE\x9F\x9B\xCF\x9F\x3C\xCF\x34\x97\x5C\x45\x9D\xAE\x5E\x45\xCC\x15\x10\xBD\x96\x2C\xB7\x9C\x19\x3F\x94\x10\xCE\x9E\x9B\x73\x9E\x45\xC6\x96\x9D\x82\x49\x45\xC7\x9F\x9D",
"\xCF\x97\x9C\xC9\x91\x9E\xD1\x9D\x5A\xF0\x98\x53\xAC\x9F\x9E\xBA\x94\x12\x14\x34\x9F\xD4\x29\x9D\xFF\x0B\x9D\x9E\x15\x9B\x11\x80\x36\xE6\x92\x9D\xCF\x99\x9A\x93\x4B\x9D\xBF\x1F\x48\x87\x6D\x4D\x07\xA8\x97\x4D\x5F\x9C\xFA\x97\x9C\x04\x28\x9F\xCB\x94\x12\xF9\x15\x49\xB8\x9C\x9F\xFF\x93\xA0\x0C\xA0\x20\x9E\x1A\x9E\xBE\x94\xA0\xAC\x9A\x9F\x95\x49\x1F\xB8\x9E\x9E\x40\x21\x9D\x05\x8F\x25\x1D\xA8\x9F\x20\xA1\x22\xC1\x9D\x3A\xD1\x14\x9C\xA8\x5E\x2F\x11\x87\x81\xFA\x9C\x38\x24\xA7\x9B\x26\xA9\xA1\x1F\xAB\xA1\x2A\xA7\x5B\x2C\xA8\x4B\x85\x6F\xA2\x31\xA5\xA4\xA2\x54\x07\x34\xA6\x36\x61\x48\x58\xFA\x9C\x44\x39\xA5\x97\x3B\xAA\xA4\xEF\x99\xA2\xB9\x1B\xA2\xF4\x9D\xA2\x65\x04\xA4\xC3\x96\xA4\xC5\x9C\xA3\x9F\x1D\x4B\x4C\xA1\x1C\x34\x66\x72\x25\xAE\xA5\xFD\x97\x9B\x54\xA2\x58\x40\xA7\xA5\x42\xAE\x56\x5A\xAC\x3A\x5C\xA3\xA3\x9F\x25\x5C\xE7\x9A\x94\xFA\x9C\x9B\xF8\x91\xA5\xD0\x3C\xA6\x6A\x6B\x61\x6B\xA3\xA5\x6D\xA0\x4F\x6F\xA1\x1F\x86\x57\xA4\xE5\x9F\x8A\xD7\x99\x24\xFA\x9D\x88\x37\x99\xA7\x66\xA1\xA4\x7D\xAD\x54\x56\xA0\xA8\x4B\x53\xA4\xB7\x9A\x2C\x5D\xA2\xA5\xCF\x37\x81\x12\xA3\x9B\x24\x11\x82\xD1\x90\x9C\xB7\x91\x82\x8C\x60\x8E\x65\x0B\xA0\x91\xAB\x97\x83\x1C\x9C\x08\x9F\x9E\x83\xA4\x2D\x82\x98\x1C\x49\xAB\xA7\x22\x81\x20\xC1\x1B\x9D\xC5\x2E\x9F\x0C\x1E\xA1\x00\x0E\x9E\xB8\x91\xAB\xBC\x13\xAB\x9B\xA8\x58\xE9\x98\x9F\x80\x9E\xAB\x90\xA1\x9F\x85\x65\x97\xFA\x9C\x19\x34\x68\x9B\xAF\xAB\x29\x9B\x9A\x94\xA8\xA1\x9F\xBA\x5F\x0F\xEE\x9B\x9F\xF6\x31\x2E\xDE\x98\x11\xC8\xA5\x97\x61\x2C\x99\x73\xA2\x8C\xAE\x5A\x94\xC5\xAC\xA7\xD6\xAA\x94\xDF\xA4\xA9\xCA\xAE\x56\xDA\xA0\x48\xDD\x98\x11\x27\x0E\xAD\xF8\x91\xAE\xD4\xA3\xAE\x8D\xA5\xAE\x6F\x87\x9C\xF3\xA8\xAE\x74\xA1\x96\x74\x06\xA0\xC2\x90\xA7\x64\x96\x26\xBF\x11\x9A\x7C\x81\x20\xDB\x97\x80\xBA\xA1\x67\xF4\xA4\x9F\xF6\xAF\x86\xD5\xAF\xAF\xBA\x57\x9C\x0C\xB8\xA6\xB8\x4A\x5B\x02\xB0\xA3\x5B\xA5\xB0\x73\x07\xB0\x38\x29\x95\xB9\x12\xA1\x37\xA0\x7F\xF8\x92\xAA\x75\x9D\x33\x10\x53\xB1\xE4\xA6\x8C\x81\x51\x2E\xFA\x96\x72\x1A\x7D\xA9\x34\xB7\x9B\xFA\x95\x2C\x4C\x89\x9B\x18\x4E\x74\xF8\x98\xB0\x82\x83\xB2\x13\xA6\x14\x15\xA7\xB2\x5E\xA7\xB1\x75\x9E\xB3\x4F\x9B\xAA\x24\x13\xA6\xF8\x98\xA1\xF0\xA4\x9F\x48\xB0\x20\xAF\xA8\xA9\x72\xA3\x34\x2D\xB0\xB0\xF9\x91\x1C\x04\x23\xB3\x24\xB1\x1C\x26\x77\xA6\xF8\x95\xB2\x0C\x19\x89\xB9\x9E\xB4\x15\x89\xAC\xFF\xAA\x4B\xAF\xAA\xB2\x9A\x25\x8C\x04\x17\x49\x8B\x9A\xB4\x46\x1C\x19\x7E\x81\xAA\xF5\xA6\x58\xBA\x4C\xB2\xF9\xAE\xB2\x4D\x58\xAD\x24\x18\xAB\xF1\xAB\xAB\x0F\xBF\x9E\x7A\x9F\x25\x7A\xBD\x38\xF4\x5D\x54\xE7\xAC\xAE\x69\xB1\x58\xEB\xA8\xA2\x81\xA3\x49\xEF\xA9\x7D\x81\xB8\x10\xFD\xA0\x42\x77\xB0\xA3\x79\xB8\xAF\x88\xBC\xB7\x00\x2C\xAF\x68\xB7\xB5\x6A\xB3\xAA\x2C\x72\x10\x45\x7F\xB2\x38\x24\x10\x91\x79\xB0\x93\xBC\x82\x95\xBC\x6D\x83\xB1\x9D\x85\xB0\xB4\x56\xBB\xB7\xFB\x76\xB1\xA1\xB6\xBB\xA3\xB5\x97\x21\x87\xBA\x0D\xA9\xBA\x03\x1B\xBA\x3F\xB8\xA4\x61\xB1\x1C\x8C\x35\x01\x44\xBC\x10\x6B\xBB\xAD\x2B\xBD\xAA\x46\x38\x84\x52\x8C\xAC\xC1\x15\x49\x47\x85\xB3\x5D\xB6\x9F\x18\x17\x01\xC9\xBC\xB8\x2D\xB4\x9A\xC0\xBB\x63\x7B\x83\xBC\x0E\xA1\x1C\x9E\x18\x01\xD6\xB5\x9F\x46\x1C\x38\x64\xB7\xA1\x5E\xA8\xBC\xF4\x90\x99\x28\x98\x1B\xCB\xBC\x10\xC3\x27\xAA\x6E\xB3\x10\x70\xBE\x67\xB8\x9D\xA4\x18\x19\x01\xDB\xB4\x10\xAF\xA0\x24\x17\x9F\x1B\x88\x9E\x23\xD1\x9D\xAC\x18\x1A\x01\xFF\xBF\x9C\x93\x91\xBD\xCE\xB3\x10\xD5\x71\x99\x19\x2B\x9D\xAD\xBC\x79\xAF\xB3\x10\x97\xB0\x9E\xF8\x9D\xC0\x12\xCE\x06\xBF\x10\xBF\x58\x7F\x2B\xA0\xBF\xBE\xAD\xA7\x92\x21\xC8\x1B\x1B\xB5\xA4\x1D\xBB\x73\x65\x9F\xB1\xDF\xB7\x72\x2D\x73\xBC\x15\xC5\x7A\x17\xC4\xC3\x0C\x1F\xB8\xD9\x2C\xC1\xF1\xBE\xC1\x0F\xC2\x10\x11\xCB\xC3\xB8\xB4\xC2\xD4\x7D\x91\x1D\xC9\xC2\x5B\xAB\xC2\x55\x60\xB2\x0C\x12\xBC\x49\xB0\xB3\xAC\xAC\x10\x1B\x0B\xC0\xBE\x9A\x98\xFA\xB7\xBF\x55\x4E\x6F\x7E\x63\xC3\xDA\x98\x11\xEE\xBC\xAD\x5C\xC1\xBB\xCF\x94\xC5\x9E\x64\xC0\x3B\x9F\x6F\xC7\x9D\xC5\xD1\x95\xC0\xBA\x16\xC4\xF8\xB5\x8C\x18\x52\x28\x1F\xC5\xC2\x50\x7A\xC5\x8C\xA4\x2D\x9C\x15\xC7\x38\xC5\x2D\x62\xC2\x6C\x64\xCC\x66\x09\x92\x6C\xC7\x95\xC7\xB8\x9A\xC6\x65\x0C\xC6\x57\xCE\xC7\x00\x0F\xC6\xB6\x27\xB8\x38\x9B\xB9\xE7\xB2\xBD\x24\x1F\x1B\x1D\x0F\xC8\xD7",
"\xB2\xB4\x56\xC4\xC9\xC0\x11\xC9\x18\x1F\x01\x98\xC5\xC9\x35\x13\xA2\x52\xC0\x9D\xE0\xA5\xA8\x99\xA4\xAB\xC3\xA8\x22\xC6\xBC\xB9\xD0\xA8\x11\x53\xB4\xCA\x55\xB6\xCA\x94\x1B\xA4\xA8\xC3\x1B\xAA\xC5\xC3\xA2\xC1\x2E\x54\xBC\x2C\xC2\xA1\xCB\xB5\xA1\xB4\x35\x15\xC7\x4F\xAE\xC5\xCA\xB7\xA9\xAE\xCA\xCB\x8F\xA2\xCB\xBC\x1A\x9F\xBF\x11\x02\x9D\xCE\xC9\x83\x1A\xBE\xA1\xC3\xBF\x25\x23\x10\xCD\xB8\xC8\x6F\xB8\xC5\x63\xCE\xA9\x46\x1F\x1B\xB5\x8D\xCC\x4E\xC4\x12\x38\xBE\xCD\xD8\xBB\xCD\x18\x15\x02\xE2\xC5\xBC\x4B\xBF\xC2\xAB\xC3\xCC\xA3\xC0\xA3\x86\xAC\xB9\x38\x92\xAE\xCA\xC2\xAF\xE7\xCF\xCD\x46\x11\xCE\xF4\x9B\xB3\x0C\x19\xC1\x61\xC1\xB2\xDE\xB9\xC9\x96\xC6\xCD\xCF\x9A\xCF\x96\xBD\xB3\xFE\xC9\xB0\x72\xB5\x13\x4C\xB4\x9F\x66\xB4\x10\xFC\xC3\xC5\x07\xD3\xBC\xAD\xCE\xCE\xA5\xC4\xA7\x14\xB7\xAF\xF3\xC2\xB8\xF5\xC6\xB3\xC1\x13\xB4\xF9\xCE\xA5\xBC\xA8\x9B\x58\xA0\xD0\x9F\xC5\xCB\x75\x9D\xD0\x03\x11\xD2\x18\xB5\xA9\x6E\xA4\xCC\x14\xDF\xCA\x02\xA7\x17\xC8\xC6\xAB\x9F\xA6\xD2\xE1\x28\xD2\x02\x1A\xD2\x75\x98\xA5\x13\xD1\xA7\xC6\xCA\xA9\xBC\xC6\xA3\xC1\x1E\xA4\x4D\xB0\xD2\xB9\xBD\xB9\xF2\x9E\xA2\x2E\xDE\xD3\x86\xB7\xCC\xB5\xAA\x9F\x0B\xDF\x9E\x38\xD0\x00\x3A\xD1\x2E\x3C\xDB\xD4\x5B\xAF\xCE\xB5\xB8\xD4\xD7\xAB\x9B\x18\x16\xC8\xD4\x23\xD5\x55\xDD\x2D\x57\xDD\xCE\x4C\xD4\xBB\x2B\x46\x9E\x62\x4B\xA8\x36\xDD\x2D\x62\xD7\xD4\x38\x96\xA9\x66\xD9\xD5\x15\xDC\xCB\xA7\xC1\xAC\x1B\xD9\xD7\x98\xC0",
};

			void XmlGetParserBuffer(vl::stream::MemoryStream& stream)
			{
				vl::stream::MemoryStream compressedStream;
				for (vint i = 0; i < parserBufferRows; i++)
				{
					vint size = i == parserBufferRows - 1 ? parserBufferRemain : parserBufferBlock;
					compressedStream.Write((void*)parserBuffer[i], size);
				}
				compressedStream.SeekFromBegin(0);
				vl::stream::LzwDecoder decoder;
				vl::stream::DecoderStream decoderStream(compressedStream, decoder);
				vl::collections::Array<vl::vuint8_t> buffer(65536);
				while (true)
				{
					vl::vint size = decoderStream.Read(&buffer[0], 65536);
					if (size == 0) break;
					stream.Write(&buffer[0], size);
				}
				stream.SeekFromBegin(0);
			}
/***********************************************************************
Unescaping Function Foward Declarations
***********************************************************************/

			extern void XmlMergeTextFragment(vl::collections::List<vl::Ptr<XmlNode>>& value, const vl::collections::List<vl::regex::RegexToken>& tokens);
			extern void XmlUnescapeAttributeValue(vl::parsing::ParsingToken& value, const vl::collections::List<vl::regex::RegexToken>& tokens);
			extern void XmlUnescapeCData(vl::parsing::ParsingToken& value, const vl::collections::List<vl::regex::RegexToken>& tokens);
			extern void XmlUnescapeComment(vl::parsing::ParsingToken& value, const vl::collections::List<vl::regex::RegexToken>& tokens);

/***********************************************************************
Parsing Tree Conversion Driver Implementation
***********************************************************************/

			class XmlTreeConverter : public vl::parsing::ParsingTreeConverter
			{
			public:
				using vl::parsing::ParsingTreeConverter::SetMember;

				void Fill(vl::Ptr<XmlNode> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
				}

				void Fill(vl::Ptr<XmlText> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->content, obj->GetMember(L"content"), tokens);
				}

				void Fill(vl::Ptr<XmlCData> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					if(SetMember(tree->content, obj->GetMember(L"content"), tokens))
					{
						XmlUnescapeCData(tree->content, tokens);
					}
				}

				void Fill(vl::Ptr<XmlAttribute> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->name, obj->GetMember(L"name"), tokens);
					if(SetMember(tree->value, obj->GetMember(L"value"), tokens))
					{
						XmlUnescapeAttributeValue(tree->value, tokens);
					}
				}

				void Fill(vl::Ptr<XmlComment> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					if(SetMember(tree->content, obj->GetMember(L"content"), tokens))
					{
						XmlUnescapeComment(tree->content, tokens);
					}
				}

				void Fill(vl::Ptr<XmlElement> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->name, obj->GetMember(L"name"), tokens);
					SetMember(tree->closingName, obj->GetMember(L"closingName"), tokens);
					SetMember(tree->attributes, obj->GetMember(L"attributes"), tokens);
					if(SetMember(tree->subNodes, obj->GetMember(L"subNodes"), tokens))
					{
						XmlMergeTextFragment(tree->subNodes, tokens);
					}
				}

				void Fill(vl::Ptr<XmlInstruction> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->name, obj->GetMember(L"name"), tokens);
					SetMember(tree->attributes, obj->GetMember(L"attributes"), tokens);
				}

				void Fill(vl::Ptr<XmlDocument> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->prologs, obj->GetMember(L"prologs"), tokens);
					SetMember(tree->rootElement, obj->GetMember(L"rootElement"), tokens);
				}

				vl::Ptr<vl::parsing::ParsingTreeCustomBase> ConvertClass(vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)override
				{
					if(obj->GetType()==L"Text")
					{
						vl::Ptr<XmlText> tree = new XmlText;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<XmlNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"CData")
					{
						vl::Ptr<XmlCData> tree = new XmlCData;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<XmlNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Attribute")
					{
						vl::Ptr<XmlAttribute> tree = new XmlAttribute;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<XmlNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Comment")
					{
						vl::Ptr<XmlComment> tree = new XmlComment;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<XmlNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Element")
					{
						vl::Ptr<XmlElement> tree = new XmlElement;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<XmlNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Instruction")
					{
						vl::Ptr<XmlInstruction> tree = new XmlInstruction;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<XmlNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Document")
					{
						vl::Ptr<XmlDocument> tree = new XmlDocument;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<XmlNode>(), obj, tokens);
						return tree;
					}
					else 
						return 0;
				}
			};

			vl::Ptr<vl::parsing::ParsingTreeCustomBase> XmlConvertParsingTreeNode(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				XmlTreeConverter converter;
				vl::Ptr<vl::parsing::ParsingTreeCustomBase> tree;
				converter.SetMember(tree, node, tokens);
				return tree;
			}

/***********************************************************************
Parsing Tree Conversion Implementation
***********************************************************************/

			vl::Ptr<XmlText> XmlText::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return XmlConvertParsingTreeNode(node, tokens).Cast<XmlText>();
			}

			vl::Ptr<XmlCData> XmlCData::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return XmlConvertParsingTreeNode(node, tokens).Cast<XmlCData>();
			}

			vl::Ptr<XmlAttribute> XmlAttribute::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return XmlConvertParsingTreeNode(node, tokens).Cast<XmlAttribute>();
			}

			vl::Ptr<XmlComment> XmlComment::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return XmlConvertParsingTreeNode(node, tokens).Cast<XmlComment>();
			}

			vl::Ptr<XmlElement> XmlElement::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return XmlConvertParsingTreeNode(node, tokens).Cast<XmlElement>();
			}

			vl::Ptr<XmlInstruction> XmlInstruction::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return XmlConvertParsingTreeNode(node, tokens).Cast<XmlInstruction>();
			}

			vl::Ptr<XmlDocument> XmlDocument::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return XmlConvertParsingTreeNode(node, tokens).Cast<XmlDocument>();
			}

/***********************************************************************
Parser Function
***********************************************************************/

			vl::Ptr<vl::parsing::ParsingTreeNode> XmlParseDocumentAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"XDocument");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				return node;
			}

			vl::Ptr<vl::parsing::ParsingTreeNode> XmlParseDocumentAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return XmlParseDocumentAsParsingTreeNode(input, table, errors, codeIndex);
			}

			vl::Ptr<XmlDocument> XmlParseDocument(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"XDocument");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				if(node && errors.Count()==0)
				{
					return XmlConvertParsingTreeNode(node, state.GetTokens()).Cast<XmlDocument>();
				}
				return 0;
			}

			vl::Ptr<XmlDocument> XmlParseDocument(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return XmlParseDocument(input, table, errors, codeIndex);
			}

			vl::Ptr<vl::parsing::ParsingTreeNode> XmlParseElementAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"XElement");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				return node;
			}

			vl::Ptr<vl::parsing::ParsingTreeNode> XmlParseElementAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return XmlParseElementAsParsingTreeNode(input, table, errors, codeIndex);
			}

			vl::Ptr<XmlElement> XmlParseElement(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"XElement");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				if(node && errors.Count()==0)
				{
					return XmlConvertParsingTreeNode(node, state.GetTokens()).Cast<XmlElement>();
				}
				return 0;
			}

			vl::Ptr<XmlElement> XmlParseElement(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return XmlParseElement(input, table, errors, codeIndex);
			}

/***********************************************************************
Table Generation
***********************************************************************/

			vl::Ptr<vl::parsing::tabling::ParsingTable> XmlLoadTable()
			{
				vl::stream::MemoryStream stream;
				XmlGetParserBuffer(stream);
				vl::Ptr<vl::parsing::tabling::ParsingTable> table=new vl::parsing::tabling::ParsingTable(stream);
				table->Initialize();
				return table;
			}

		}
	}
}
