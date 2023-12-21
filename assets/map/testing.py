def generate_xml(start_id, end_id):
    xml_content = ''
    for i in range(start_id, end_id + 1):
        xml_content += f'<block>\n'
        xml_content += f'    <id>{i}</id>\n'
        xml_content += f'    <type>grass</type>\n'
        xml_content += f'</block>\n'

    return xml_content

start_id = 11
end_id = 144

xml_data = generate_xml(start_id, end_id)

# Write to a file or do something with the generated XML data
with open('blocks.xml', 'w') as file:
    file.write(xml_data)
