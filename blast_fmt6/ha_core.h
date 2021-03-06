/*  Copyright (C) 2009 David A. C. Beck

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#define BLAST_FMT6_QUERY_ID_FIELDNAME "query_id"
#define BLAST_FMT6_SUBJECT_ID_FIELDNAME "subject_id"
#define BLAST_FMT6_PERCENT_IDENTITY_FIELDNAME "percent_identity"
#define BLAST_FMT6_ALIGNMENT_LENGTH_FIELDNAME "alignment_length"
#define BLAST_FMT6_MISMATCHES_FIELDNAME "mismatches"
#define BLAST_FMT6_GAP_OPENS_FIELDNAME "gap_opens"
#define BLAST_FMT6_QUERY_START_FIELDNAME "query_start"
#define BLAST_FMT6_QUERY_END_FIELDNAME "query_end"
#define BLAST_FMT6_SUBJECT_START_FIELDNAME "subject_start"
#define BLAST_FMT6_SUBJECT_END_FIELDNAME "subject_end"
#define BLAST_FMT6_EVALUE_FIELDNAME "evalue"
#define BLAST_FMT6_BIT_SCORE_FIELDNAME "bit_score"

#define BLAST_FMT6_VARCHAR "VARCHAR"
#define BLAST_FMT6_FLOAT "FLOAT"
#define BLAST_FMT6_DOUBLE "DOUBLE"
#define BLAST_FMT6_LONG "INT"

enum blast_fmt6_field { QUERY_ID = 0, SUBJECT_ID = 1, PERCENT_IDENTITY = 2, ALIGNMENT_LENGTH = 3, \
	MISMATCHES = 4, GAP_OPENS = 5, QUERY_START = 6, QUERY_END = 7, \
	SUBJECT_START = 8, SUBJECT_END = 9, EVALUE = 10, BIT_SCORE = 11, DONE = 12 };

struct blast_fmt6_field_info {
	char *fieldname;
	enum blast_fmt6_field state;
	enum blast_fmt6_field next_state;
	uint type;
	char *type_text;
} blast_fmt6_fields[] = { \
	{ BLAST_FMT6_QUERY_ID_FIELDNAME, QUERY_ID, SUBJECT_ID, MYSQL_TYPE_VARCHAR, BLAST_FMT6_VARCHAR }, \
	{ BLAST_FMT6_SUBJECT_ID_FIELDNAME, SUBJECT_ID, PERCENT_IDENTITY, MYSQL_TYPE_VARCHAR, BLAST_FMT6_VARCHAR }, \
	{ BLAST_FMT6_PERCENT_IDENTITY_FIELDNAME, PERCENT_IDENTITY, ALIGNMENT_LENGTH, MYSQL_TYPE_FLOAT, BLAST_FMT6_FLOAT }, \
	{ BLAST_FMT6_ALIGNMENT_LENGTH_FIELDNAME, ALIGNMENT_LENGTH, MISMATCHES, MYSQL_TYPE_LONG, BLAST_FMT6_LONG }, \
	{ BLAST_FMT6_MISMATCHES_FIELDNAME, MISMATCHES, GAP_OPENS, MYSQL_TYPE_LONG, BLAST_FMT6_LONG }, \
	{ BLAST_FMT6_GAP_OPENS_FIELDNAME, GAP_OPENS, QUERY_START, MYSQL_TYPE_LONG, BLAST_FMT6_LONG }, \
	{ BLAST_FMT6_QUERY_START_FIELDNAME, QUERY_START, QUERY_END, MYSQL_TYPE_LONG, BLAST_FMT6_LONG }, \
	{ BLAST_FMT6_QUERY_END_FIELDNAME, QUERY_END, SUBJECT_START, MYSQL_TYPE_LONG, BLAST_FMT6_LONG }, \
	{ BLAST_FMT6_SUBJECT_START_FIELDNAME, SUBJECT_START, SUBJECT_END, MYSQL_TYPE_LONG, BLAST_FMT6_LONG }, \
	{ BLAST_FMT6_SUBJECT_END_FIELDNAME, SUBJECT_END, EVALUE, MYSQL_TYPE_LONG, BLAST_FMT6_LONG }, \
	{ BLAST_FMT6_EVALUE_FIELDNAME, EVALUE, BIT_SCORE, MYSQL_TYPE_DOUBLE, BLAST_FMT6_DOUBLE }, \
	{ BLAST_FMT6_BIT_SCORE_FIELDNAME, BIT_SCORE, DONE, MYSQL_TYPE_FLOAT, BLAST_FMT6_FLOAT }, \
	NULL \
};
